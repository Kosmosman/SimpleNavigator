//
// Created by joaquind on 13.12.23.
//

#ifndef SIMPLENAVIGATOR_GRAPH_H
#define SIMPLENAVIGATOR_GRAPH_H

#include <string>
#include <vector>

namespace s21 {
using matrix_t = std::vector<std::vector<u_int>>;

class Graph {
 public:
  Graph() = default;

  const matrix_t& GetMatrix() const { return matrix_; }
  void SetMatrix(const matrix_t& matrix) { matrix_ = matrix; }

  void LoadGraphFromFile(const std::string& filename);
  void ExportGraphToDot(const std::string& filename);

 private:
  matrix_t matrix_{};
};

}  // namespace s21

#endif  // SIMPLENAVIGATOR_GRAPH_H
