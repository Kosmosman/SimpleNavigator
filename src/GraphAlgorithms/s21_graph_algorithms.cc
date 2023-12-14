//
// Created by joaquind on 13.12.23.
//

#include <climits>
#include <map>
#include "s21_graph_algorithms.h"

namespace s21 {
// std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
//                                                    int start_vertex) {
//   // Implement depth-first search here
// }

// std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
//                                                      int start_vertex) {
//   // Implement breadth-first search here
// }

    size_t GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
        --vertex1, --vertex2;
        std::vector<bool> visited(graph.GetSize());
        std::vector<size_t> distance(graph.GetSize(), UINT_MAX);
        std::multimap<size_t, size_t> s{{0, static_cast<unsigned long>(vertex1)}};
        distance[vertex1] = 0;
        while (!s.empty()) {
            auto position{*s.begin()};
            s.erase(s.begin());
            if (!visited[position.second]) {
                for (size_t i{0}; i < graph.GetSize(); ++i) {
                    if (graph.GetMatrix()[position.second][i] && i != position.second) {
                        distance[i] = std::min(distance[i], position.first + graph.GetMatrix()[position.second][i]);
                        s.insert({distance[i], i});
                    }
                }
            }
            if (position.second == vertex2) break;
            visited[position.second] = true;
        }
        return distance[vertex2];
    }

// matrix_t GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
//   // Implement Floyd-Warshall algorithm here
// }

// matrix_t GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
//   // Implement Prim's algorithm here
// }
// TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
//   // Implement ant colony algorithm here
// }
}  // namespace s21