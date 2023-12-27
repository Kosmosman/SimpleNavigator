//
// Created by joaquind on 13.12.23.
//

#include "s21_graph_algorithms.h"

#include <algorithm>
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
    if (position.second == vertex2)
      break;
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
        if (i == j)
          continue;
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

matrix_t GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
  auto size{graph.GetSize()};
  int best_way{INT_MAX};
  matrix_t result(size, std::vector<int>(size));
  for (auto i{0}; i < graph.GetSize(); ++i) {
    std::vector<bool> visited(size);
    std::vector<int> min_path(size, INT_MAX);
    std::vector<int> min_path_vertex(size);
    matrix_t tmp_result(size, std::vector<int>(size));
    int way{};
    min_path[i] = 0;
    min_path_vertex[i] = i;

    for (int j{}; j < size; ++j) {
      int next_v{-1};
      for (int k{}; k < size; ++k) {
        if (!visited[k] && (next_v == -1 || min_path[k] < min_path[next_v]))
          next_v = k;
      }
      if (min_path[next_v] == INT_MAX)
        return matrix_t{};
      visited[next_v] = true;
      way += min_path[next_v];
      if (way >= best_way)
        break;
      tmp_result[min_path_vertex[next_v]][next_v] = min_path[next_v];
      for (int k{}; k < size; ++k) {
        if (graph.GetMatrix()[next_v][k] &&
            graph.GetMatrix()[next_v][k] < min_path[k]) {
          min_path[k] = graph.GetMatrix()[next_v][k];
          min_path_vertex[k] = next_v;
        }
        if (graph.GetMatrix()[k][next_v] &&
            graph.GetMatrix()[k][next_v] < min_path[k]) {
          min_path[k] = graph.GetMatrix()[k][next_v];
          min_path_vertex[k] = next_v;
        }
      }
    }
    if (way < best_way) {
      result = std::move(tmp_result);
      best_way = way;
    }
  }
  return result;
}

TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
  AntCoefficients settings{};
  std::vector<std::vector<AntPath>> path(graph.GetSize(),
                                         std::vector<AntPath>(graph.GetSize()));
  auto len{graph.GetSize()};
  auto &matrix{graph.GetMatrix()};
  for (auto i{0}; i < len; ++i) {
    for (auto j{0}; j < len; ++j) {
      path[i][j].length = matrix[i][j];
    }
  }
}
} // namespace s21