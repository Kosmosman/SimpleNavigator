//
// Created by joaquind on 13.12.23.
//

#include <Graph/Graph.h>

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

  adjMatrix_.resize(size, std::vector<u_int>(size));

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      file >> adjMatrix_[i][j];
    }
  }

  file.close();
}

void Graph::ExportGraphToDot(const std::string& filename) {
  std::ofstream dotFile(filename);

  if (!dotFile.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  size_t size = GetSize();

  dotFile << "graph {" << std::endl;

  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      if (adjMatrix_[i][j] != 0) {
        dotFile << i << " -- " << j << ";\n";
      }
    }
  }

  dotFile << "}" << std::endl;

  dotFile.close();
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