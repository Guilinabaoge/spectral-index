//
// Created by ssunah on 11/20/18.
//

#ifndef SUBGRAPHMATCHING_FILTERVERTICES_H
#define SUBGRAPHMATCHING_FILTERVERTICES_H

#include "graph/graph.h"
#include <vector>
#include <Eigen/Core>

using namespace Eigen;

class FilterVertices {
public:
    static bool LDFFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,bool isEigenCheck,int top_s,
                          vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static bool NLFFilter(Graph* data_graph, Graph* query_graph, ui** &candidates, ui* &candidates_count,bool isEigenCheck,int top_s,
                          vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static bool GQLFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,bool isEigenCheck,int top_s,
                          vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static bool TSOFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,
                          ui *&order,TreeNode *&tree,bool isEigenCheck,int top_s,
                          vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static bool CFLFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,
                              ui *&order, TreeNode *&tree, bool isEigenCheck,int top_s,
                          vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static bool DPisoFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,
                            ui *&order, TreeNode *&tree, bool isEigenCheck,int top_s,
                            vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);

    static bool CECIFilter(Graph *data_graph, Graph *query_graph, ui **&candidates, ui *&candidates_count,
                           ui *&order, TreeNode *&tree,   std::vector<std::unordered_map<VertexID, std::vector<VertexID >>> &TE_Candidates,
                           std::vector<std::vector<std::unordered_map<VertexID, std::vector<VertexID>>>> &NTE_Candidates,bool isEigenCheck,int top_s);

    // static bool VCFilter(const Graph* data_graph, const Graph* query_graph, ui **&candidates, ui *&candidates_count);

    static void computeCandidateWithNLF(Graph *data_graph, Graph *query_graph, VertexID query_vertex, ui &count, ui *buffer,
                                        vector<vector<double>> &datagraph_eigen, vector<vector<double>> &querygraph_eigen, bool isEigenCheck, int top_s);


    static void computeCandidateWithLDF(Graph *data_graph, Graph *query_graph, VertexID query_vertex,
                                        ui &count, ui *buffer = NULL);

    static void generateCandidates(const Graph *data_graph, const Graph *query_graph, VertexID query_vertex,
                                      VertexID *pivot_vertices, ui pivot_vertices_count, VertexID **candidates,
                                      ui *candidates_count, ui *flag, ui *updated_flag);

    static void pruneCandidates(const Graph *data_graph, const Graph *query_graph, VertexID query_vertex,
                                   VertexID *pivot_vertices, ui pivot_vertices_count, VertexID **candidates,
                                   ui *candidates_count, ui *flag, ui *updated_flag);


    static void
    printCandidatesInfo(const Graph *query_graph, ui *candidates_count, std::vector<ui> &optimal_candidates_count);

    static void sortCandidates(ui** candidates, ui* candidates_count, ui num);

    static double computeCandidatesFalsePositiveRatio(const Graph *data_graph, const Graph *query_graph, ui **candidates,
                                                          ui *candidates_count, std::vector<ui> &optimal_candidates_count);


    static void compactCandidatesWrapper(ui **&candidates, ui *&candidates_count, ui query_vertex_num,MatrixXd &query_eigen,MatrixXd &data_eigen,int top_s);
    static void generateCandidatesWrapper(const Graph *data_graph, const Graph *query_graph, VertexID query_vertex,
                                              VertexID *pivot_vertices, ui pivot_vertices_count, VertexID **candidates,
                                              ui *candidates_count, ui *flag, ui *updated_flag,vector<vector<double>> &query_eigen,vector<vector<double>> &data_eigen,int top_s);
private:
    static void allocateBuffer(const Graph* data_graph, const Graph* query_graph, ui** &candidates, ui* &candidates_count);
    static bool verifyExactTwigIso(const Graph *data_graph, const Graph *query_graph, ui data_vertex, ui query_vertex,
                                   bool **valid_candidates, int *left_to_right_offset, int *left_to_right_edges,
                                   int *left_to_right_match, int *right_to_left_match, int* match_visited,
                                   int* match_queue, int* match_previous);
    static void compactCandidates(ui** &candidates, ui* &candidates_count, ui query_vertex_num);
    static bool isCandidateSetValid(ui** &candidates, ui* &candidates_count, ui query_vertex_num);



};


#endif //SUBGRAPHMATCHING_FILTERVERTICES_H
