#include "s21_view.h"

namespace s21 {

void View::displayHelpMessage() {
  std::cout << "CLI Application for Graph Algorithms\n";
  displayUsageMessage();
  std::cout << "Type of algorithm:\n";
  std::cout << "- dfs <start_vertex>: Perform Depth-First Search starting from "
               "a given vertex.\n";
  std::cout << "- bfs <start_vertex>: Perform Breadth-First Search starting "
               "from a given vertex.\n";
  std::cout << "- shortest-path <vertex1> <vertex2>: Find the shortest path "
               "between two vertices.\n";
  std::cout << "- all-paths: Calculate shortest paths between all pairs of "
               "vertices.\n";
  std::cout << "- least-spanning-tree: Compute the Least Spanning Tree of the "
               "graph.\n";
  std::cout << "Example:./SimpleNavigator graph_file.txt dfs 0\n";
}

void View::displayUsageMessage() {
  std::cout
      << "Usage: ./SimpleNavigator <filename> <type_of_algorithm> [<args>]\n";
}

void View::displaySuccessMessage(const std::string &message) {
  std::cout << message << '\n';
}

void View::displayErrorMessage(const std::string &message) {
  std::cerr << message << '\n';
}

void View::printMatrix(matrix_t graphMatrix) {
  for (size_t i = 0; i < graphMatrix.size(); i++) {
    for (size_t j = 0; j < graphMatrix[i].size(); j++) {
      std::cout << graphMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void View::printVector(std::vector<int> graphVector) {
  for (int v : graphVector) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

}  // namespace s21