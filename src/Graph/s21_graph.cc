//
// Created by joaquind on 13.12.23.
//

#include "s21_graph.h"

#include <fstream>
#include <vector>

namespace s21 {
void Graph::LoadGraphFromFile(const std::string &filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  int size = 0;
  file >> size;

  adjMatrix_.resize(size, std::vector<int>(size));

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      file >> adjMatrix_[i][j];
    }
  }

  file.close();
}

void Graph::ExportGraphToDot(const std::string &filename) {
  std::ofstream file(filename);
  if (!file) {
    throw std::runtime_error("Could not open file");
  }

  file << "graph {\n";
  for (int i = 0; i < adjMatrix_.size(); ++i) {
    for (int j = 0; j < adjMatrix_[i].size(); ++j) {
      if (adjMatrix_[i][j] != 0) {
        file << i << " -- " << j << ";\n";
      }
    }
  }
  file << "}\n";

  file.close();
}

void Graph::print() {
  size_t size = GetSize();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      std::cout << adjMatrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
}  // namespace s21