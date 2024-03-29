//
// Created by ssunah on 11/21/18.
//

#ifndef SUBGRAPHMATCHING_GENERATEFILTERINGPLAN_H
#define SUBGRAPHMATCHING_GENERATEFILTERINGPLAN_H


#include "graph/graph.h"
#include "configuration/types.h"
#include <Eigen/Core>

using namespace Eigen;

class GenerateFilteringPlan {
public:
    static void generateTSOFilterPlan(Graph *data_graph, Graph *query_graph, TreeNode *&tree,
                                           VertexID *&order,int top_s,vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static void generateCFLFilterPlan(Graph *data_graph, Graph *query_graph, TreeNode *&tree,
                                      VertexID *&order, int &level_count, ui *&level_offset,bool isEigenCheck,int top_s,
                                      vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static void generateDPisoFilterPlan(Graph *data_graph, Graph *query_graph, TreeNode *&tree,
                                        VertexID *&order);
    static void generateCECIFilterPlan(Graph *data_graph, Graph *query_graph, TreeNode *&tree,
                                       VertexID *&order);
private:
    static VertexID selectTSOFilterStartVertex(Graph *data_graph, Graph *query_graph,
                                               int top_s,vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static VertexID selectCFLFilterStartVertex(Graph *data_graph, Graph *query_graph,bool isEigenCheck,
                                               int top_s,vector<vector<double>> &querygraph_eigenvalue,vector<vector<double>> &datagraph_eigenvalue);
    static VertexID selectDPisoStartVertex(Graph *data_graph, Graph *query_graph);
    static VertexID selectCECIStartVertex(Graph *data_graph, Graph *query_graph);
};


#endif //SUBGRAPHMATCHING_GENERATEFILTERINGPLAN_H
