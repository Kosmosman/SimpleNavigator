//
// Created by joaquind on 13.12.23.
//

#ifndef GRAPH_S21_GRAPH_H_
#define GRAPH_S21_GRAPH_H_

#include <iostream>
#include <string>
#include <vector>

namespace s21 {
using matrix_t = std::vector<std::vector<int>>;

class Graph {
 public:
  Graph() = default;

  void addEdge(int src, int dest, int weight) {
    adjMatrix_[src][dest] = weight;
  }
  void deleteEdge(int src, int dest) { adjMatrix_[src][dest] = 0; }

  size_t GetSize() { return adjMatrix_.size(); }

  const matrix_t &GetMatrix() const { return adjMatrix_; }
  void SetMatrix(const matrix_t &matrix) { adjMatrix_ = matrix; }

  void LoadGraphFromFile(const std::string &filename);
  void ExportGraphToDot(const std::string &filename);

  void print();

 private:
  matrix_t adjMatrix_{};
};

}  // namespace s21

#endif  // GRAPH_S21_GRAPH_H_