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
  virtual ~GraphAlgorithms() = default;

  std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);

  std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
  int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  matrix_t GetShortestPathsBetweenAllVertices(Graph &graph);

  matrix_t GetLeastSpanningTree(Graph &graph);
  TsmResult SolveTravelingSalesmanProblem(Graph &graph);
};

}  // namespace s21

#endif  // GRAPH_S21_GRAPHALGORITHMS_H_