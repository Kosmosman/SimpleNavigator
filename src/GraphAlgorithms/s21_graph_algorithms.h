//
// Created by joaquind on 13.12.23.
//

#ifndef GRAPH_S21_GRAPHALGORITHMS_H_
#define GRAPH_S21_GRAPHALGORITHMS_H_

#include <vector>

#include "../Graph/s21_graph.h"

namespace s21 {

struct TsmResult {
  std::vector<int> vertices;
  double distance;
};

class GraphAlgorithms {
 public:
  static std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
  static std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);

  static size_t GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  static matrix_t GetShortestPathsBetweenAllVertices(Graph &graph);

  static matrix_t GetLeastSpanningTree(Graph &graph);
  static TsmResult SolveTravelingSalesmanProblem(Graph &graph);
};

}  // namespace s21

#endif  // GRAPH_S21_GRAPHALGORITHMS_H_