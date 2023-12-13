//
// Created by joaquind on 13.12.23.
//

#include "Graph.h"

#include <fstream>
#include <sstream>
#include <vector>

namespace s21 {
void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  int size = 0;
  file >> size;

  matrix_.resize(size, std::vector<u_int>(size));

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      file >> matrix_[i][j];
    }
  }

  file.close();
}

void Graph::ExportGraphToDot(const std::string& filename) {
  std::ofstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  file << "graph {\n";

  for (size_t i = 0; i < matrix_.size(); ++i) {
    for (size_t j = 0; j < matrix_.size(); ++j) {
      if (matrix_[i][j] != 0) {
        file << i << " -- " << j << ";\n";
      }
    }
  }

  file << "}\n";

  file.close();
}
}  // namespace s21