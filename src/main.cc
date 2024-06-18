#include "Graph/s21_graph.h"
#include "GraphAlgorithms/s21_graph_algorithms.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

namespace s21 {

void performDfs(Graph graph, int startVertex) {
  try {
    GraphAlgorithms algos;
    std::vector<int> result = algos.DepthFirstSearch(graph, startVertex);
    std::cout << "DFS Result: ";
    for (int v : result) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error performing DFS: " << e.what() << '\n';
  }
}

void performBfs(Graph graph, int startVertex) {
  try {
    GraphAlgorithms algos;
    std::vector<int> result = algos.BreadthFirstSearch(graph, startVertex);
    std::cout << "BFS Result: ";
    for (int v : result) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error performing DFS: " << e.what() << '\n';
  }
}

void performShortestPath(Graph graph, int firstVertex, int secondVertex) {
  try {
    GraphAlgorithms algos;
    size_t pathLength =
        algos.GetShortestPathBetweenVertices(graph, firstVertex, secondVertex);
    std::cout << "Shortest Path Length: " << pathLength << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error calculating shortest path: " << e.what() << '\n';
  }
};

void performAllPaths(Graph graph) {
  try {
    GraphAlgorithms algos;
    matrix_t paths = algos.GetShortestPathsBetweenAllVertices(graph);
    std::cout << "Shortest Paths Between All Vertices:\n";
    for (int i = 0; i < paths.size(); ++i) {
      for (int j = 0; j < paths[i].size(); ++j) {
        std::cout << paths[i][j] << " ";
      }
      std::cout << "\n";
    }
  } catch (const std::exception &e) {
    std::cerr << "Error calculating all paths: " << e.what() << '\n';
  }
};

void performLeastSpanningTree(Graph graph) {
  try {
    GraphAlgorithms algos;
    matrix_t lst = algos.GetLeastSpanningTree(graph);
    std::cout << "Least Spanning Tree:\n";
    for (int i = 0; i < lst.size(); ++i) {
      for (int j = 0; j < lst[i].size(); ++j) {
        std::cout << lst[i][j] << " ";
      }
      std::cout << "\n";
    }
  } catch (const std::exception &e) {
    std::cerr << "Error calculating least spanning tree: " << e.what() << '\n';
  }
};

int main(int argc, char *argv[]) {
  bool showHelp = false;
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--help") == 0) {
      showHelp = true;
      break;
    }
  }

  if (showHelp) {
    std::cout << "CLI Application for Graph Algorithms\n";
    std::cout
        << "Usage: ./SimpleNavigator <filename> <type_of_algorithm> [<args>]\n";
    std::cout << "Commands:\n";
    std::cout << "- dfs <start_vertex>: Perform Depth-First Search starting "
                 "from a given vertex.\n";
    std::cout << "- bfs <start_vertex>: Perform Breadth-First Search starting "
                 "from a given vertex.\n";
    std::cout << "- shortest-path <vertex1> <vertex2>: Find the shortest path "
                 "between two vertices.\n";
    std::cout << "- all-paths: Calculate shortest paths between all pairs of "
                 "vertices.\n";
    std::cout << "- least-spanning-tree: Compute the Least Spanning Tree of "
                 "the graph.\n";
    std::cout << "- tsp: Solve the Traveling Salesman Problem.\n";
    std::cout << "Example:./SimpleNavigator graph_file.txt dfs 0\n";
    return 0;
  }

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0]
              << "<filename> <type_of_algorithm> [<args>]\n";
    return 1;
  }

  std::string algorithmType(argv[2]);
  std::string filename(argv[1]);

  std::ifstream file(filename);
  if (!file.good()) {
    std::cerr << "File '" << filename << "' not found.\n";
    return 1;
  }

  try {
    Graph graph;
    graph.LoadGraphFromFile(filename);
    std::cout << "Graph loaded successfully.\n";
    graph.print();

    if (algorithmType == "dfs") {
      if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " " << algorithmType
                  << " <start_vertex>\n";
        return 1;
      }

      performDfs(graph, std::stoi(argv[3]));
    } else if (algorithmType == "bfs") {
      if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " " << algorithmType
                  << " <start_vertex>\n";
        return 1;
      }
      performBfs(graph, std::stoi(argv[3]));
    } else if (algorithmType == "shortest-path") {
      if (argc < 5) {
        std::cerr << "Usage: " << argv[0]
                  << " shortest-path <vertex1> <vertex2>\n";
        return 1;
      }
      performShortestPath(graph, std::stoi(argv[3]), std::stoi(argv[4]));
    } else if (algorithmType == "all-paths") {
      performAllPaths(graph);
    } else if (algorithmType == "least-spanning-tree") {
      performLeastSpanningTree(graph);
    } else {
      std::cerr << "Unknown command: " << algorithmType << ".\n";
    }
  } catch (const std::exception &e) {
    std::cerr << "Error loading graph: " << e.what() << '\n';
  }

  return 0;
}

} // namespace s21