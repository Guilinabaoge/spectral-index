//
// Created by ssunah on 12/3/18.
//

#include <functional>
#include <map>
#include <chrono>
#include <future>
#include <thread>
#include <fstream>
#include <numeric>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>



#include "matchingcommand.h"
#include "graph/graph.h"
#include "GenerateFilteringPlan.h"
#include "FilterVertices.h"
#include "BuildTable.h"
#include "GenerateQueryPlan.h"
#include "EvaluateQuery.h"
#include "IO.h"
#include "eigenHelper.h"



#define NANOSECTOSEC(elapsed_time) ((elapsed_time)/(double)1000000000)
#define BYTESTOMB(memory_cost) ((memory_cost)/(double)(1024 * 1024))

size_t enumerate(Graph* data_graph, Graph* query_graph, Edges*** edge_matrix, ui** candidates, ui* candidates_count,
                ui* matching_order, size_t output_limit) {
    static ui order_id = 0;

    order_id += 1;

    auto start = std::chrono::high_resolution_clock::now();



    size_t call_count = 0;
    size_t embedding_count = EvaluateQuery::LFTJ(data_graph, query_graph, edge_matrix, candidates, candidates_count,
                               matching_order, output_limit, call_count).embedding_cnt;


    auto end = std::chrono::high_resolution_clock::now();
    double enumeration_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
#ifdef SPECTRUM
    if (EvaluateQuery::exit_) {
        printf("Spectrum Order %u status: Timeout\n", order_id);
    }
    else {
        printf("Spectrum Order %u status: Complete\n", order_id);
    }
#endif
    printf("Spectrum Order %u Enumerate time (seconds): %.4lf\n", order_id, NANOSECTOSEC(enumeration_time_in_ns));
    printf("Spectrum Order %u #Embeddings: %zu\n", order_id, embedding_count);
    printf("Spectrum Order %u Call Count: %zu\n", order_id, call_count);
    printf("Spectrum Order %u Per Call Count Time (nanoseconds): %.4lf\n", order_id, enumeration_time_in_ns / (call_count == 0 ? 1 : call_count));


    return embedding_count;
}

void spectrum_analysis(Graph* data_graph, Graph* query_graph, Edges*** edge_matrix, ui** candidates, ui* candidates_count,
                       size_t output_limit, std::vector<std::vector<ui>>& spectrum, size_t time_limit_in_sec) {

    for (auto& order : spectrum) {
        std::cout << "----------------------------" << std::endl;
        ui* matching_order = order.data();
        GenerateQueryPlan::printSimplifiedQueryPlan(query_graph, matching_order);

        std::future<size_t> future = std::async(std::launch::async, [data_graph, query_graph, edge_matrix, candidates, candidates_count,
                                                                     matching_order, output_limit](){
            return enumerate(data_graph, query_graph, edge_matrix, candidates, candidates_count, matching_order, output_limit);
        });

        std::cout << "execute...\n";
        std::future_status status;
        do {
            status = future.wait_for(std::chrono::seconds(time_limit_in_sec));
            if (status == std::future_status::deferred) {
                std::cout << "Deferred\n";
                exit(-1);
            } else if (status == std::future_status::timeout) {
#ifdef SPECTRUM
                EvaluateQuery::exit_ = true;
#endif
            }
        } while (status != std::future_status::ready);
    }
}

string experiment(Graph *data_graph, Graph *query_graph){
    ui** candidates = NULL;
    ui* candidates_count = NULL;
    ui* tso_order = NULL;
    TreeNode* tso_tree = NULL;
    ui* cfl_order = NULL;
    TreeNode* cfl_tree = NULL;
    ui* dpiso_order = NULL;
    TreeNode* dpiso_tree = NULL;
    TreeNode* ceci_tree = NULL;
    ui* ceci_order = NULL;
    std::vector<std::unordered_map<VertexID, std::vector<VertexID >>> TE_Candidates;
    std::vector<std::vector<std::unordered_map<VertexID, std::vector<VertexID>>>> NTE_Candidates;

    bool (*functptr[7])(Graph*, Graph* , ui**& , ui*&, ui*&,TreeNode *&,std::vector<std::unordered_map<VertexID, std::vector<VertexID >>> &,std::vector<std::vector<std::unordered_map<VertexID, std::vector<VertexID>>>> &NTE_Candidates,bool,int);
    functptr[0] = FilterVertices::LDFWrapper;
    functptr[1] = FilterVertices::NLFWrapper;
    functptr[2] = FilterVertices::GQLWrapper;
    functptr[3] = FilterVertices::TSOWrapper;
    functptr[4] = FilterVertices::CFLWrapper;
    functptr[5] = FilterVertices::DPisoWrapper;
    functptr[6] = FilterVertices::CECIFilter;

    int sum=0;
    int top_s = 10;
    if(query_graph->getVerticesCount()==4){
        top_s = 4;
    }
    if(query_graph->getVerticesCount()==8){
        top_s = 8;
    }

    static int results[14];
    int counter = 0;

    for(int i =0; i<7;i++){
        functptr[i](data_graph, query_graph, candidates, candidates_count,ceci_order,ceci_tree,TE_Candidates,NTE_Candidates,true,top_s);
        results[counter] = accumulate(candidates_count, candidates_count+query_graph->getVerticesCount(), sum);
        counter++;
        functptr[i](data_graph, query_graph, candidates, candidates_count,ceci_order,ceci_tree,TE_Candidates,NTE_Candidates,false,top_s);
        results[counter] = accumulate(candidates_count, candidates_count+query_graph->getVerticesCount(), sum);
        counter++;
    }

    string results_string = "";
    for (int i=0; i<14; i++){
        results_string.append(std::to_string(results[i])+",");
    }
    results_string.pop_back();
    results_string.append("\n");

    return results_string;
}

//int main(int argc, char** argv){
//    //    MatrixXd datagraph_eigenvalue(data_graph->getVerticesCount(), 35);
//    //    MTcalc12(data_graph,data_graph->getGraphMaxDegree(),datagraph_eigenvalue,true,35);
//    //    saveData("wordnet.csv", datagraph_eigenvalue);
//
//    //  -d ../../test/reallife_dataset/wordnet/data_graph/wordnet.graph -q ../../test/reallife_dataset/wordnet/query_graph/query_dense_8_1.graph -filter GQL -order GQL -engine LFTJ -num MAX -eigen 1 -tops 4
//    int query_number[200];
//    for (int i=0;i<200;i++){
//        query_number[i] = i+1;
//    }
//    //Yeast
//    int query_vertices_dense[5]={4,8,16,24,32};
//    int query_vertices_sparse[4]={8,16,24,32};
//
//    //Wordnet
//    int query_vertices_dense_v2[5]={4,8,12,16,20};
//    int query_vertices_sparse_v2[4]={8,12,16,20};
//
//
//    string querypath[1800];
//    int counter = 0;
//
//    for(int i=0; i<5;i++){
//        for (int j=0;j<200;j++){
//            std::ostringstream oss;
//            oss << "../../test/reallife_dataset/wordnet/query_graph/query_dense_" << query_vertices_dense_v2[i] <<"_" << query_number[j]<< ".graph";
//            std::string var = oss.str();
//            querypath[counter] = var;
//            counter++;
//        }
//    }
//
//    for(int i=0; i<4;i++){
//        for (int j=0;j<200;j++){
//            std::ostringstream oss;
//            oss << "../../test/reallife_dataset/wordnet/query_graph/query_dense_" << query_vertices_sparse_v2[i] <<"_" << query_number[j]<< ".graph";
//            std::string var = oss.str();
//            querypath[counter] = var;
//            counter++;
//        }
//    }
//
//    std::string input_data_graph_file = "../../test/reallife_dataset/wordnet/data_graph/wordnet.graph";
//    Graph* data_graph = new Graph(true);
//    data_graph->loadGraphFromFile(input_data_graph_file);
//
//    std::ofstream myfile;
//    myfile.open ("wordnetexperiment.csv",std::ios_base::app);
//    myfile << "Query_NUmber,LDF+EF,LDF,NLF+EF,NLF,GQL+EF,GQL,TSOF+EF,TSOF,CFL+EF,CFL,DPiso+EF,Dpiso,CECIF+EF,CECIF\n";
//    myfile.close();
//
//    for (int i=771; i<1800;i++){
//        Graph* query_graph = new Graph(true);
//        query_graph->loadGraphFromFile(querypath[i]);
//        query_graph->buildCoreTable();
//        string results = to_string(i)+",";
//        string results2 = results.append(experiment(data_graph,query_graph));
//        myfile.open ("wordnetexperiment.csv",std::ios_base::app);
//        myfile<<results2;
//        myfile.close();
//        cout << i << endl;
//    }
//
//
//
//
//
//}

int solveGraphQuery(string dgraph_path, string qgraph_path, string filter, string order, string engine,
                    string eigen, string tops, int* candidate_vertices, int* result_vertices,int* embedding_cnt){
    int argc = 0;
    char** argv;
    MatchingCommand command(argc, argv);
    std::string input_query_graph_file = qgraph_path;
    std::string input_data_graph_file = dgraph_path;
    std::string input_filter_type = filter;
    std::string input_order_type = order;
    std::string input_engine_type = engine;
    std::string input_max_embedding_num = "MAX";
    std::string input_time_limit = command.getTimeLimit();
    std::string input_order_num = command.getOrderNum();
    std::string input_distribution_file_path = command.getDistributionFilePath();
    std::string input_csr_file_path = command.getCSRFilePath();
    std::string input_iseigen = eigen;
    std::string input_tops = tops;
    /**
     * Output the command line information.
     */
#ifdef PRINT
    std::cout << "Command Line:" << std::endl;
    std::cout << "\tData Graph CSR: " << input_csr_file_path << std::endl;
    std::cout << "\tData Graph: " << input_data_graph_file << std::endl;
    std::cout << "\tQuery Graph: " << input_query_graph_file << std::endl;
    std::cout << "\tFilter Type: " << input_filter_type << std::endl;
    std::cout << "\tOrder Type: " << input_order_type << std::endl;
    std::cout << "\tEngine Type: " << input_engine_type << std::endl;
    std::cout << "\tOutput Limit: " << input_max_embedding_num << std::endl;
    std::cout << "\tTime Limit (seconds): " << input_time_limit << std::endl;
    std::cout << "\tOrder Num: " << input_order_num << std::endl;
    std::cout << "\tDistribution File Path: " << input_distribution_file_path << std::endl;
    std::cout << "\tWith eigen filter?: " << input_iseigen << std::endl;
    std::cout << "\tTop-s eigen value?: " << input_tops << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
#endif
    /**
     * Load input graphs.
     */
#ifdef PRINT
    std::cout << "Load graphs..." << std::endl;
#endif


    auto start = std::chrono::high_resolution_clock::now();

    Graph* query_graph = new Graph(true);
    query_graph->loadGraphFromFile(input_query_graph_file);
    query_graph->buildCoreTable();

    Graph* data_graph = new Graph(true);

    if (input_csr_file_path.empty()) {
        data_graph->loadGraphFromFile(input_data_graph_file);
    }
    else {
        std::string degree_file_path = input_csr_file_path + "_deg.bin";
        std::string edge_file_path = input_csr_file_path + "_adj.bin";
        std::string label_file_path = input_csr_file_path + "_label.bin";
        data_graph->loadGraphFromFileCompressed(degree_file_path, edge_file_path, label_file_path);
    }

    auto end = std::chrono::high_resolution_clock::now();

    double load_graphs_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

//    MatrixXd datagraph_eigenvalue(data_graph->getVerticesCount(), 35);
//    MTcalc12(data_graph,data_graph->getGraphMaxDegree(),datagraph_eigenvalue,true,35);
//    saveData("dblp.csv", datagraph_eigenvalue);

#ifdef PRINT
    std::cout << "-----" << std::endl;
    std::cout << "Query Graph Meta Information" << std::endl;
    query_graph->printGraphMetaData();
    std::cout << "-----" << std::endl;
    data_graph->printGraphMetaData();

    std::cout << "--------------------------------------------------------------------" << std::endl;
#endif
    /**
     * Start queries.
     */


#ifdef PRINT
    std::cout << "Start queries..." << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << "Filter candidates..." << std::endl;
#endif

    start = std::chrono::high_resolution_clock::now();

    bool isEigenCheck;
    int top_s = std::stoi( input_tops);
    istringstream(input_iseigen) >> isEigenCheck;


    ui** candidates = NULL;
    ui* candidates_count = NULL;
    ui* tso_order = NULL;
    TreeNode* tso_tree = NULL;
    ui* cfl_order = NULL;
    TreeNode* cfl_tree = NULL;
    ui* dpiso_order = NULL;
    TreeNode* dpiso_tree = NULL;
    TreeNode* ceci_tree = NULL;
    ui* ceci_order = NULL;
    std::vector<std::unordered_map<VertexID, std::vector<VertexID >>> TE_Candidates;
    std::vector<std::vector<std::unordered_map<VertexID, std::vector<VertexID>>>> NTE_Candidates;
    if (input_filter_type == "LDF") {
        FilterVertices::LDFFilter(data_graph, query_graph, candidates, candidates_count,isEigenCheck,top_s);
    } else if (input_filter_type == "NLF") {
        FilterVertices::NLFFilter(data_graph, query_graph, candidates, candidates_count,isEigenCheck,top_s);
    } else if (input_filter_type == "GQL") {
        FilterVertices::GQLFilter(data_graph, query_graph, candidates, candidates_count,isEigenCheck,top_s);
    } else if (input_filter_type == "TSO") {
        FilterVertices::TSOFilter(data_graph, query_graph, candidates, candidates_count, tso_order, tso_tree,isEigenCheck,top_s);
    } else if (input_filter_type == "CFL") {
        FilterVertices::CFLFilter(data_graph, query_graph, candidates, candidates_count, cfl_order, cfl_tree,isEigenCheck,top_s);
    } else if (input_filter_type == "DPiso") {
        FilterVertices::DPisoFilter(data_graph, query_graph, candidates, candidates_count, dpiso_order, dpiso_tree,isEigenCheck,top_s);
    } else if (input_filter_type == "CECI") {
        FilterVertices::CECIFilter(data_graph, query_graph, candidates, candidates_count, ceci_order, ceci_tree, TE_Candidates, NTE_Candidates,isEigenCheck,top_s);
    }  else {
        std::cout << "The specified filter type '" << input_filter_type << "' is not supported." << std::endl;
        exit(-1);
    }

    // Sort the candidates to support the set intersections
    // TODO figure out why CECI dosen't work, read the paper.
    if (input_filter_type != "CECI")
        FilterVertices::sortCandidates(candidates, candidates_count, query_graph->getVerticesCount());

    end = std::chrono::high_resolution_clock::now();
    double filter_vertices_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();


    // Compute the candidates false positive ratio.
#ifdef OPTIMAL_CANDIDATES
    std::vector<ui> optimal_candidates_count;
    double avg_false_positive_ratio = FilterVertices::computeCandidatesFalsePositiveRatio(data_graph, query_graph, candidates,
                                                                                          candidates_count, optimal_candidates_count);
    FilterVertices::printCandidatesInfo(query_graph, candidates_count, optimal_candidates_count);
#endif

#ifdef PRINT
    std::cout << "-----" << std::endl;
    std::cout << "Build indices..." << std::endl;
#endif

    start = std::chrono::high_resolution_clock::now();

    Edges ***edge_matrix = NULL;
    if (input_filter_type != "CECI") {
        edge_matrix = new Edges **[query_graph->getVerticesCount()];
        for (ui i = 0; i < query_graph->getVerticesCount(); ++i) {
            edge_matrix[i] = new Edges *[query_graph->getVerticesCount()];
        }
        BuildTable::buildTables(data_graph, query_graph, candidates, candidates_count, edge_matrix);
    }

    end = std::chrono::high_resolution_clock::now();
    double build_table_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    size_t memory_cost_in_bytes = 0;
    if (input_filter_type != "CECI") {
        memory_cost_in_bytes = BuildTable::computeMemoryCostInBytes(query_graph, candidates_count, edge_matrix);
#ifdef PRINT
        BuildTable::printTableCardinality(query_graph, edge_matrix);
#endif
    }
    else {
        memory_cost_in_bytes = BuildTable::computeMemoryCostInBytes(query_graph, candidates_count, ceci_order, ceci_tree,
                                                                    TE_Candidates, NTE_Candidates);
#ifdef PRINT
        BuildTable::printTableCardinality(query_graph, ceci_tree, ceci_order, TE_Candidates, NTE_Candidates);
#endif
    }

#ifdef PRINT
    std::cout << "-----" << std::endl;
    std::cout << "Generate a matching order..." << std::endl;
#endif

    start = std::chrono::high_resolution_clock::now();

    ui* matching_order = NULL;
    ui* pivots = NULL;
    ui** weight_array = NULL;

    size_t order_num = 0;
    sscanf(input_order_num.c_str(), "%zu", &order_num);

    std::vector<std::vector<ui>> spectrum;
    if (input_order_type == "QSI") {
        GenerateQueryPlan::generateQSIQueryPlan(data_graph, query_graph, edge_matrix, matching_order, pivots);
    } else if (input_order_type == "GQL") {
        GenerateQueryPlan::generateGQLQueryPlan(data_graph, query_graph, candidates_count, matching_order, pivots);
    } else if (input_order_type == "TSO") {
        if (tso_tree == NULL) {
            GenerateFilteringPlan::generateTSOFilterPlan(data_graph, query_graph, tso_tree, tso_order,top_s);
        }
        GenerateQueryPlan::generateTSOQueryPlan(query_graph, edge_matrix, matching_order, pivots, tso_tree, tso_order);
    } else if (input_order_type == "CFL") {
        if (cfl_tree == NULL) {
            int level_count;
            ui* level_offset;
            GenerateFilteringPlan::generateCFLFilterPlan(data_graph, query_graph, cfl_tree, cfl_order, level_count, level_offset,isEigenCheck,top_s);
            delete[] level_offset;
        }
        GenerateQueryPlan::generateCFLQueryPlan(data_graph, query_graph, edge_matrix, matching_order, pivots, cfl_tree, cfl_order, candidates_count);
    } else if (input_order_type == "DPiso") {
        if (dpiso_tree == NULL) {
            GenerateFilteringPlan::generateDPisoFilterPlan(data_graph, query_graph, dpiso_tree, dpiso_order);
        }

        GenerateQueryPlan::generateDSPisoQueryPlan(query_graph, edge_matrix, matching_order, pivots, dpiso_tree, dpiso_order,
                                                   candidates_count, weight_array);
    }
    else if (input_order_type == "CECI") {
        GenerateQueryPlan::generateCECIQueryPlan(query_graph, ceci_tree, ceci_order, matching_order, pivots);
    }
    else if (input_order_type == "RI") {
        GenerateQueryPlan::generateRIQueryPlan(data_graph, query_graph, matching_order, pivots);
    }
    else if (input_order_type == "VF2PP") {
        GenerateQueryPlan::generateVF2PPQueryPlan(data_graph, query_graph, matching_order, pivots);
    }
    else if (input_order_type == "Spectrum") {
        GenerateQueryPlan::generateOrderSpectrum(query_graph, spectrum, order_num);
    }
    else {
        std::cout << "The specified order type '" << input_order_type << "' is not supported." << std::endl;
    }

    end = std::chrono::high_resolution_clock::now();
    double generate_query_plan_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    if (input_order_type != "Spectrum") {
        GenerateQueryPlan::checkQueryPlanCorrectness(query_graph, matching_order, pivots);
#ifdef PRINT
        GenerateQueryPlan::printSimplifiedQueryPlan(query_graph, matching_order);
#endif
    }
    else {
#ifdef PRINT
        std::cout << "Generate " << spectrum.size() << " matching orders." << std::endl;
#endif

    }

#ifdef PRINT
    std::cout << "-----" << std::endl;
    std::cout << "Enumerate..." << std::endl;
#endif

    size_t output_limit = 0;
    size_t embedding_count = 0;
    if (input_max_embedding_num == "MAX") {
        output_limit = std::numeric_limits<size_t>::max();
    }
    else {
        sscanf(input_max_embedding_num.c_str(), "%zu", &output_limit);
    }


#if ENABLE_QFLITER == 1
    EvaluateQuery::qfliter_bsr_ graph_ = BuildTable::qfliter_bsr_graph_;
#endif

    size_t call_count = 0;
    size_t time_limit = 0;
    sscanf(input_time_limit.c_str(), "%zu", &time_limit);

    start = std::chrono::high_resolution_clock::now();

    if (input_engine_type == "EXPLORE") {
        embedding_count = EvaluateQuery::exploreGraph(data_graph, query_graph, edge_matrix, candidates,
                                                      candidates_count, matching_order, pivots, output_limit, call_count);
    } else if (input_engine_type == "LFTJ") {


        enumResult s = EvaluateQuery::LFTJ(data_graph, query_graph, edge_matrix, candidates, candidates_count,
                                           matching_order, output_limit, call_count);



        // For each candidate, count it as true candidate(result_counter++) if it exits in one of the final match.
        int result_counter = 0;

        int sum = 0;

        *candidate_vertices = accumulate(candidates_count,candidates_count+query_graph->getVerticesCount(),sum);
        *result_vertices = s.true_cand_sum;
        *embedding_cnt = s.embedding_cnt;


    } else if (input_engine_type == "GQL") {
        embedding_count = EvaluateQuery::exploreGraphQLStyle(data_graph, query_graph, candidates, candidates_count,
                                                             matching_order, output_limit, call_count);
    } else if (input_engine_type == "QSI") {
        embedding_count = EvaluateQuery::exploreQuickSIStyle(data_graph, query_graph, candidates, candidates_count,
                                                             matching_order, pivots, output_limit, call_count);
    }
    else if (input_engine_type == "DPiso") {
        embedding_count = EvaluateQuery::exploreDPisoStyle(data_graph, query_graph, dpiso_tree,
                                                           edge_matrix, candidates, candidates_count,
                                                           weight_array, dpiso_order, output_limit,
                                                           call_count);
//        embedding_count = EvaluateQuery::exploreDPisoRecursiveStyle(data_graph, query_graph, dpiso_tree,
//                                                           edge_matrix, candidates, candidates_count,
//                                                           weight_array, dpiso_order, output_limit,
//                                                           call_count);
    }
    else if (input_engine_type == "Spectrum") {
        spectrum_analysis(data_graph, query_graph, edge_matrix, candidates, candidates_count, output_limit, spectrum, time_limit);
    }
    else if (input_engine_type == "CECI") {
        embedding_count = EvaluateQuery::exploreCECIStyle(data_graph, query_graph, ceci_tree, candidates, candidates_count, TE_Candidates,
                                                          NTE_Candidates, ceci_order, output_limit, call_count);
    }
    else {
        std::cout << "The specified engine type '" << input_engine_type << "' is not supported." << std::endl;
        exit(-1);
    }

    end = std::chrono::high_resolution_clock::now();
    double enumeration_time_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

#ifdef DISTRIBUTION
    std::ofstream outfile (input_distribution_file_path , std::ofstream::binary);
    outfile.write((char*)EvaluateQuery::distribution_count_, sizeof(size_t) * data_graph->getVerticesCount());
    delete[] EvaluateQuery::distribution_count_;
#endif

#ifdef PRINT
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "Release memories..." << std::endl;
#endif
    /**
     * Release the allocated memories.
     */
    delete[] candidates_count;
    delete[] tso_order;
    delete[] tso_tree;
    delete[] cfl_order;
    delete[] cfl_tree;
    delete[] dpiso_order;
    delete[] dpiso_tree;
    delete[] ceci_order;
    delete[] ceci_tree;
    delete[] matching_order;
    delete[] pivots;
    for (ui i = 0; i < query_graph->getVerticesCount(); ++i) {
        delete[] candidates[i];
    }
    delete[] candidates;

    if (edge_matrix != NULL) {
        for (ui i = 0; i < query_graph->getVerticesCount(); ++i) {
            for (ui j = 0; j < query_graph->getVerticesCount(); ++j) {
                delete edge_matrix[i][j];
            }
            delete[] edge_matrix[i];
        }
        delete[] edge_matrix;
    }
    if (weight_array != NULL) {
        for (ui i = 0; i < query_graph->getVerticesCount(); ++i) {
            delete[] weight_array[i];
        }
        delete[] weight_array;
    }

    delete query_graph;
    delete data_graph;

    /**
     * End.
     */
#ifdef PRINT
    std::cout << "--------------------------------------------------------------------" << std::endl;
    double preprocessing_time_in_ns = filter_vertices_time_in_ns + build_table_time_in_ns + generate_query_plan_time_in_ns;
    double total_time_in_ns = preprocessing_time_in_ns + enumeration_time_in_ns;

    printf("Load graphs time (seconds): %.4lf\n", NANOSECTOSEC(load_graphs_time_in_ns));
    printf("Filter vertices time (seconds): %.4lf\n", NANOSECTOSEC(filter_vertices_time_in_ns));
    printf("Build table time (seconds): %.4lf\n", NANOSECTOSEC(build_table_time_in_ns));
    printf("Generate query plan time (seconds): %.4lf\n", NANOSECTOSEC(generate_query_plan_time_in_ns));
    printf("Enumerate time (seconds): %.4lf\n", NANOSECTOSEC(enumeration_time_in_ns));
    printf("Preprocessing time (seconds): %.4lf\n", NANOSECTOSEC(preprocessing_time_in_ns));
    printf("Total time (seconds): %.4lf\n", NANOSECTOSEC(total_time_in_ns));
    printf("Memory cost (MB): %.4lf\n", BYTESTOMB(memory_cost_in_bytes));
    printf("#Embeddings: %zu\n", embedding_count);
    printf("Call Count: %zu\n", call_count);
    printf("Per Call Count Time (nanoseconds): %.4lf\n", enumeration_time_in_ns / (call_count == 0 ? 1 : call_count));
    std::cout << "End." << std::endl;
#endif
    return 0;
}


void experiment2(string data_graph,string query_graph,string eigen,string top_s){
    //In this experiment I find out what are the vertices in the candidate set has been embedded into valid matches.

    // -d ../../test/reallife_dataset/wordnet/data_graph/wordnet.graph -q ../../test/reallife_dataset/wordnet/query_graph/query_dense_12_2.graph -filter GQL -order GQL -engine LFTJ -num MAX -eigen 1 -tops 10
    //TODO Missing CECI
    string filters[6] = {"LDF","NLF","GQL","TSO","CFL","DPiso"};

    int candidate_counts[6];
    int results[6];
    int embeddings[6];


    for(int i = 0; i<6;i++){
        cout<<i<<endl;
        int* candidate_count = new int;
        int* candidate_true = new int;
        int* embedding_cnt = new int;
        solveGraphQuery(data_graph, query_graph, filters[i], "GQL", "LFTJ", eigen, top_s,
                        candidate_count, candidate_true,embedding_cnt);
        candidate_counts[i] = *candidate_count;
        results[i]= *candidate_true;
        embeddings[i] = *embedding_cnt;

        delete candidate_count;
        delete candidate_true;

    }

    cout<<"--------------------------"<<endl;
    cout<<"Candidates"<<endl;
    for(int i=0; i<6;i++){
        cout<<candidate_counts[i]<<",";
    }
    cout<<" "<<endl;
    cout<<"Candidates_true"<<endl;
    for(int i=0; i<6;i++){
        cout<<results[i]<<",";
    }
    cout<<" "<<endl;
    cout<<"Embedding count"<<endl;
    for(int i=0; i<6;i++){
        cout<<embeddings[i]<<",";
    }
    cout<<" "<<endl;
    cout<<"--------------------------"<<endl;
}


int main(int argc, char** argv) {
    string data_graph_path = "../../test/reallife_dataset/dblp/data_graph/dblp.graph";
    string query_graph_path = "../../test/reallife_dataset/dblp/query_graph/query_dense_8_6.graph";


    Graph* data_graph = new Graph(true);
    data_graph->loadGraphFromFile(data_graph_path);

    MatrixXd datagraph_eigenvalue(data_graph->getVerticesCount(), 35);
    MTcalc12(data_graph,data_graph->getGraphMaxDegree(),datagraph_eigenvalue,true,35);
    saveData("dblp.csv", datagraph_eigenvalue);

    cout<<"with EF"<<endl;
    experiment2(data_graph_path,query_graph_path,"1","8");
    cout<<"no EF"<<endl;
    experiment2(data_graph_path,query_graph_path,"0","8");
}