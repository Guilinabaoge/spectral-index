//
// Created by zhiwei zeng on 25/02/2023.
//
#include <chrono>
#include <future>
#include <thread>
#include <fstream>
#include <iostream>
#include <string>

#include "graph/graph.h"
#include "FilterVertices.h"
#include "IO.h"
#include "eigenHelper.h"
#include "Experiments.h"
#include "StudyPerformance.h"

void generate_datagraph_eigenvector(string data_graph_path,string csvfilename){
    Graph* data_graph = new Graph(true);
    data_graph->loadGraphFromFile(data_graph_path);

    MatrixXd datagraph_eigenvalue(data_graph->getVerticesCount(), 35);
    cout<<"Start compute eigen value"<<endl;
    MTcalc12(data_graph,data_graph->getGraphMaxDegree(),datagraph_eigenvalue,true,35);
    saveData(csvfilename, datagraph_eigenvalue);

}


int main(int argc, char** argv) {
    //    generate_datagraph_eigenvector("../../test/reallife_dataset/eu2005/data_graph/eu2005.graph","eu2005.csv");


    for(int i=0; i<5;i++){
        for(int j=1;j<201;j++){
            //yeast,hprd,uspatents,youtube,dblp,eu2005,
            vector<string> query_size_dense_1 = {"4","8","16","24","32"};
            vector<string> query_size_sparse_1 = {"8","16","24","32"};

            //human,wordnet
            vector<string> query_size_dense_2 = {"4","8","12","16","20"};
            vector<string> query_size_sparse_2 = {"8","12","16","20"};


            Experiments::datagraphEigenMatrix = "wordnet.csv";
            queryMeta meta;
            meta.dataset = "wordnet";
            meta.query_property = "dense";
            meta.query_size = query_size_dense_2[i];
            meta.query_number = to_string(j);

            std::ostringstream data;
            data << "../../test/reallife_dataset/" << meta.dataset << "/data_graph/" << meta.dataset << ".graph";
            meta.data_graph_path = data.str();

            std::ostringstream query;
            query << "../../test/reallife_dataset/" << meta.dataset << "/query_graph/query_" << meta.query_property << "_"
            << meta.query_size << "_" << meta.query_number << ".graph";
            meta.query_path = query.str();


            //Query_Name,LDF,LDF+EF,NLF,NLF+EF,GQL,GQL+EF,TSOF,TSOF+EF,CFL,CFL+EF,DPiso,DPiso+EF,KF

            matching_algo_outputs LDF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","0");
            matching_algo_outputs LDF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","1");
            matching_algo_outputs NLF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","0");
            matching_algo_outputs NLF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","1");
            matching_algo_outputs GQL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","0");
            matching_algo_outputs GQL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","1");
            matching_algo_outputs TSOF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","0");
            matching_algo_outputs TSOF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","1");
            matching_algo_outputs CFL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","0");
            matching_algo_outputs CFL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","1");
            matching_algo_outputs DPiso = Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","0");
            matching_algo_outputs DPiso_EF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","1");
            matching_algo_outputs KF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"KF","0");

            std::ostringstream oss;
            oss <<meta.query_property<<"_"<<meta.query_size<<"_"<<meta.query_number<<"," <<LDF.total_time<<"," <<LDF_EF.total_time
            <<","<<NLF.total_time<<"," <<NLF_EF.total_time<<","<<GQL.total_time<<"," <<GQL_EF.total_time<<"," <<TSOF.total_time<<"," <<TSOF_EF.total_time<<"," <<CFL.total_time
            <<"," <<CFL_EF.total_time<<","<<DPiso.total_time<<"," <<DPiso_EF.total_time<<"," <<KF.total_time<<","<<LDF.enumOutput.embedding_cnt<<","<<LDF_EF.enumOutput.embedding_cnt
            <<","<<NLF.enumOutput.embedding_cnt<<","<<NLF_EF.enumOutput.embedding_cnt<<","<<GQL.enumOutput.embedding_cnt
            <<","<<GQL_EF.enumOutput.embedding_cnt<<","<<TSOF.enumOutput.embedding_cnt<<","<<TSOF_EF.enumOutput.embedding_cnt<<","<<CFL.enumOutput.embedding_cnt
            <<","<<CFL_EF.enumOutput.embedding_cnt<<","<<DPiso.enumOutput.embedding_cnt<<","<<DPiso_EF.enumOutput.embedding_cnt<<","<<KF.enumOutput.embedding_cnt
            <<","<<LDF.candidate_count_sum<<","<<LDF.enumOutput.candidate_true_count_sum<<","<<LDF_EF.candidate_count_sum<<","<<LDF_EF.enumOutput.candidate_true_count_sum
            <<","<<NLF.candidate_count_sum<<","<<NLF.enumOutput.candidate_true_count_sum<<","<<NLF_EF.candidate_count_sum<<","<<NLF_EF.enumOutput.candidate_true_count_sum
            <<","<<GQL.candidate_count_sum<<","<<GQL.enumOutput.candidate_true_count_sum<<","<<GQL_EF.candidate_count_sum<<","<<GQL_EF.enumOutput.candidate_true_count_sum
            <<","<<TSOF.candidate_count_sum<<","<<TSOF.enumOutput.candidate_true_count_sum<<","<<TSOF_EF.candidate_count_sum<<","<<TSOF_EF.enumOutput.candidate_true_count_sum
            <<","<<CFL.candidate_count_sum<<","<<CFL.enumOutput.candidate_true_count_sum<<","<<CFL_EF.candidate_count_sum<<","<<CFL_EF.enumOutput.candidate_true_count_sum
            <<","<<DPiso.candidate_count_sum<<","<<DPiso.enumOutput.candidate_true_count_sum<<","<<DPiso_EF.candidate_count_sum<<","<<DPiso_EF.enumOutput.candidate_true_count_sum
            <<","<<KF.candidate_count_sum<<","<<KF.enumOutput.candidate_true_count_sum;

            std::string var = oss.str();

            cout<<var<<endl;

            std::ofstream myfile;
            myfile.open ("performance_experiment/wordnet.csv",std::ios_base::app);
            myfile<<var<<"\n";
            myfile.close();
        }
    }


}



//for(int i=2; i<5;i++){
//    for(int j=10;j<11;j++){
//        //yeast,hprd,uspatents,youtube,dblp,eu2005,
//        vector<string> query_size_dense_1 = {"4","8","16","24","32"};
//        vector<string> query_size_sparse_1 = {"8","16","24","32"};
//
//        //human,wordnet
//        vector<string> query_size_dense_2 = {"4","8","12","16","20"};
//        vector<string> query_size_sparse_2 = {"8","12","16","20"};
//
//
//        Experiments::datagraphEigenMatrix = "youtube.csv";
//        queryMeta meta;
//        meta.dataset = "youtube";
//        meta.query_property = "dense";
//        meta.query_size = query_size_dense_1[i];
//        meta.query_number = to_string(j);
//
//        std::ostringstream data;
//        data << "../../test/reallife_dataset/" << meta.dataset << "/data_graph/" << meta.dataset << ".graph";
//        meta.data_graph_path = data.str();
//
//        std::ostringstream query;
//        query << "../../test/reallife_dataset/" << meta.dataset << "/query_graph/query_" << meta.query_property << "_"
//        << meta.query_size << "_" << meta.query_number << ".graph";
//        meta.query_path = query.str();
//
//
//        //Query_Name,LDF,LDF+EF,NLF,NLF+EF,GQL,GQL+EF,TSOF,TSOF+EF,CFL,CFL+EF,DPiso,DPiso+EF,KF
//
//        matching_algo_outputs LDF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","0");
//        matching_algo_outputs LDF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","1");
//        matching_algo_outputs NLF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","0");
//        matching_algo_outputs NLF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","1");
//        matching_algo_outputs GQL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","0");
//        matching_algo_outputs GQL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","1");
//        matching_algo_outputs TSOF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","0");
//        matching_algo_outputs TSOF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","1");
//        matching_algo_outputs CFL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","0");
//        matching_algo_outputs CFL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","1");
//        matching_algo_outputs DPiso = Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","0");
//        matching_algo_outputs DPiso_EF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","1");
//        matching_algo_outputs KF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"KF","0");
//
//        std::ostringstream oss;
//        oss <<meta.query_property<<"_"<<meta.query_size<<"_"<<meta.query_number<<"," <<LDF.total_time<<"," <<LDF_EF.total_time
//        <<","<<NLF.total_time<<"," <<NLF_EF.total_time<<","<<GQL.total_time<<"," <<GQL_EF.total_time<<"," <<TSOF.total_time<<"," <<TSOF_EF.total_time<<"," <<CFL.total_time
//        <<"," <<CFL_EF.total_time<<","<<DPiso.total_time<<"," <<DPiso_EF.total_time<<"," <<KF.total_time<<","<<LDF.enumOutput.embedding_cnt<<","<<LDF_EF.enumOutput.embedding_cnt
//        <<","<<NLF.enumOutput.embedding_cnt<<","<<NLF_EF.enumOutput.embedding_cnt<<","<<GQL.enumOutput.embedding_cnt
//        <<","<<GQL_EF.enumOutput.embedding_cnt<<","<<TSOF.enumOutput.embedding_cnt<<","<<TSOF_EF.enumOutput.embedding_cnt<<","<<CFL.enumOutput.embedding_cnt
//        <<","<<CFL_EF.enumOutput.embedding_cnt<<","<<DPiso.enumOutput.embedding_cnt<<","<<DPiso_EF.enumOutput.embedding_cnt<<","<<KF.enumOutput.embedding_cnt
//        <<","<<LDF.candidate_count_sum<<","<<LDF.enumOutput.candidate_true_count_sum<<","<<LDF_EF.candidate_count_sum<<","<<LDF_EF.enumOutput.candidate_true_count_sum
//        <<","<<NLF.candidate_count_sum<<","<<NLF.enumOutput.candidate_true_count_sum<<","<<NLF_EF.candidate_count_sum<<","<<NLF_EF.enumOutput.candidate_true_count_sum
//        <<","<<GQL.candidate_count_sum<<","<<GQL.enumOutput.candidate_true_count_sum<<","<<GQL_EF.candidate_count_sum<<","<<GQL_EF.enumOutput.candidate_true_count_sum
//        <<","<<TSOF.candidate_count_sum<<","<<TSOF.enumOutput.candidate_true_count_sum<<","<<TSOF_EF.candidate_count_sum<<","<<TSOF_EF.enumOutput.candidate_true_count_sum
//        <<","<<CFL.candidate_count_sum<<","<<CFL.enumOutput.candidate_true_count_sum<<","<<CFL_EF.candidate_count_sum<<","<<CFL_EF.enumOutput.candidate_true_count_sum
//        <<","<<DPiso.candidate_count_sum<<","<<DPiso.enumOutput.candidate_true_count_sum<<","<<DPiso_EF.candidate_count_sum<<","<<DPiso_EF.enumOutput.candidate_true_count_sum
//        <<","<<KF.candidate_count_sum<<","<<KF.enumOutput.candidate_true_count_sum;
//
//        std::string var = oss.str();
//
//        cout<<var<<endl;
//
//        std::ofstream myfile;
//        myfile.open ("performance_experiment/youtube.csv",std::ios_base::app);
//        myfile<<var<<"\n";
//        myfile.close();
//    }
//}

//
//for(int i=4; i<5;i++){
//for(int j=1;j<36;j++){
////yeast,hprd,uspatents,youtube,dblp,eu2005,
//vector<string> query_size_dense_1 = {"4","8","16","24","32"};
//vector<string> query_size_sparse_1 = {"8","16","24","32"};
//
////human,wordnet
//vector<string> query_size_dense_2 = {"4","8","12","16","20"};
//vector<string> query_size_sparse_2 = {"8","12","16","20"};
//
//
//Experiments::datagraphEigenMatrix = "wordnet.csv";
//queryMeta meta;
//meta.dataset = "wordnet";
//meta.query_property = "dense";
//meta.query_size = query_size_dense_2[i];
//meta.query_number = to_string(j);
//
//std::ostringstream data;
//data << "../../test/reallife_dataset/" << meta.dataset << "/data_graph/" << meta.dataset << ".graph";
//meta.data_graph_path = data.str();
//
//std::ostringstream query;
//query << "../../test/reallife_dataset/" << meta.dataset << "/query_graph/query_" << meta.query_property << "_"
//<< meta.query_size << "_" << meta.query_number << ".graph";
//meta.query_path = query.str();
//
//
////Query_Name,LDF,LDF+EF,NLF,NLF+EF,GQL,GQL+EF,TSOF,TSOF+EF,CFL,CFL+EF,DPiso,DPiso+EF,KF
//
//matching_algo_outputs LDF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","0");
//matching_algo_outputs LDF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"LDF","1");
//matching_algo_outputs NLF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","0");
//matching_algo_outputs NLF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"NLF","1");
//matching_algo_outputs GQL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","0");
//matching_algo_outputs GQL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"GQL","1");
//matching_algo_outputs TSOF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","0");
//matching_algo_outputs TSOF_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"TSO","1");
//matching_algo_outputs CFL = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","0");
//matching_algo_outputs CFL_EF = Experiments::experiment3(meta.data_graph_path,meta.query_path,"CFL","1");
//matching_algo_outputs DPiso = Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","0");
//matching_algo_outputs DPiso_EF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"DPiso","1");
//matching_algo_outputs KF =Experiments::experiment3(meta.data_graph_path,meta.query_path,"KF","0");
//
//std::ostringstream oss;
//oss <<meta.query_property<<"_"<<meta.query_size<<"_"<<meta.query_number
//<<","<<LDF.candidate_count_sum<<","<<LDF_EF.candidate_count_sum
//<<","<<NLF.candidate_count_sum<<","<<NLF_EF.candidate_count_sum
//<<","<<GQL.candidate_count_sum<<","<<GQL_EF.candidate_count_sum
//<<","<<TSOF.candidate_count_sum<<","<<TSOF_EF.candidate_count_sum
//<<","<<CFL.candidate_count_sum<<","<<CFL_EF.candidate_count_sum
//<<","<<DPiso.candidate_count_sum<<","<<DPiso_EF.candidate_count_sum;
//
//std::string var = oss.str();
//
//cout<<var<<endl;
//
//std::ofstream myfile;
//myfile.open ("pruning_power_experiment/wordnet.csv",std::ios_base::app);
//myfile<<var<<"\n";
//myfile.close();
//}
//}