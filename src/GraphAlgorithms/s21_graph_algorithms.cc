//
// Created by joaquind on 13.12.23.
//

#include "s21_graph_algorithms.h"

#include <climits>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

#include "../includes/s21_queue/s21_queue.h"
#include "../includes/s21_stack/s21_stack.h"
namespace s21 {
std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  std::vector<int> visitedVertices;
  std::vector<bool> visited(graph.GetSize(), false);
  s21::Stack<int> stack;

  stack.push(start_vertex);
  visited[start_vertex] = true;
  visitedVertices.push_back(start_vertex);

  while (!stack.empty()) {
    int vertex = stack.top();

    std::vector<int> list = graph.GetMatrix()[vertex];

    for (int i = 0; i < list.size(); ++i) {
      if (list[i] && !visited[i]) {
        stack.push(i);
        visited[i] = true;
        visitedVertices.push_back(i);
        break;
      }
    }
    if (stack.top() == vertex) {
      stack.pop();
    }
  }

  return visitedVertices;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  std::vector<int> result;
  std::vector<bool> visited(graph.GetSize(), false);
  s21::Queue<int> queue;
  queue.push(start_vertex);

  while (!queue.empty()) {
    int vertex = queue.front();
    queue.pop();

    if (!visited[vertex]) {
      visited[vertex] = true;
      result.push_back(vertex);

      const s21::matrix_t &matrix = graph.GetMatrix();
      for (int i = 0; i < graph.GetSize(); ++i) {
        if (matrix[vertex][i] && !visited[i]) {
          queue.push(i);
        }
      }
    }
  }

  return result;
}

size_t GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph,
                                                       int vertex1,
                                                       int vertex2) {
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
          distance[i] =
              std::min(distance[i],
                       position.first + graph.GetMatrix()[position.second][i]);
          s.insert({distance[i], i});
        }
      }
    }
    if (position.second == vertex2) break;
    visited[position.second] = true;
  }
  return distance[vertex2];
}

matrix_t GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
  auto vertexes = graph.GetSize();
  matrix_t path_matrix(graph.GetMatrix());
  for (int k{}; k < vertexes; ++k) {
    for (int i{}; i < vertexes; ++i) {
      for (int j{}; j < vertexes; ++j) {
        if (i == j) continue;
        if (path_matrix[i][k] != 0 && path_matrix[k][j] != 0) {
          if (!path_matrix[i][j] ||
              path_matrix[i][j] > (path_matrix[i][k] + path_matrix[k][j])) {
            path_matrix[i][j] = path_matrix[i][k] + path_matrix[k][j];
          }
        }
      }
    }
  }
  return path_matrix;
}

// matrix_t GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
//   // Implement Prim's algorithm here
// }
// TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
//   // Implement ant colony algorithm here
// }
}  // namespace s21