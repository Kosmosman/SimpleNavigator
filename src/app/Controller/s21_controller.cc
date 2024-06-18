#include "s21_controller.h"
#include <cstring>
#include <fstream>
#include <string>

namespace s21 {

Controller::Controller(Model &model, View &view) : _model(model), _view(view) {}

void Controller::performDfs(Graph graph, int startVertex) {
  try {
    std::vector<int> result =
        _model.getGraphAlgorithms().DepthFirstSearch(graph, startVertex);
    std::cout << "DFS Result: ";
    for (int v : result) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error performing DFS: " << e.what() << '\n';
  }
}

void Controller::performBfs(Graph graph, int startVertex) {
  try {
    std::vector<int> result =
        _model.getGraphAlgorithms().BreadthFirstSearch(graph, startVertex);
    std::cout << "BFS Result: ";
    for (int v : result) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error performing DFS: " << e.what() << '\n';
  }
}

void Controller::performShortestPath(Graph graph, int firstVertex,
                                     int secondVertex) {
  try {
    size_t pathLength =
        _model.getGraphAlgorithms().GetShortestPathBetweenVertices(
            graph, firstVertex, secondVertex);
    std::cout << "Shortest Path Length: " << pathLength << "\n";
  } catch (const std::exception &e) {
    std::cerr << "Error calculating shortest path: " << e.what() << '\n';
  }
};

void Controller::performAllPaths(Graph graph) {
  try {
    matrix_t paths =
        _model.getGraphAlgorithms().GetShortestPathsBetweenAllVertices(graph);
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

void Controller::performLeastSpanningTree(Graph graph) {
  try {
    matrix_t lst = _model.getGraphAlgorithms().GetLeastSpanningTree(graph);
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

void Controller::executeAlgorithm(Graph &graph,
                                  const std::string &algorithmName, int argc,
                                  char *argv[]) {
  View::displaySuccessMessage("Algorithm " + algorithmName + " started");
  if (algorithmName == "dfs") {
    if (argc < 4) {
      View::displayErrorMessage("Usage: " + algorithmName + " <start_vertex>");
      return;
    }
    int startVertex = std::stoi(argv[3]);
    View::displaySuccessMessage("DFS started with start vertex " +
                                std::to_string(startVertex));
    performDfs(graph, startVertex);
  } else if (algorithmName == "bfs") {
    if (argc < 4) {
      View::displayErrorMessage("Usage: " + algorithmName + " <start_vertex>");
      return;
    }
    performBfs(graph, std::stoi(argv[3]));
  } else if (algorithmName == "shortest-path") {
    if (argc < 5) {
      View::displayErrorMessage("Usage: " + algorithmName +
                                " <vertex1> <vertex2>");
      return;
    }
    performShortestPath(graph, std::stoi(argv[3]), std::stoi(argv[4]));
  } else if (algorithmName == "all-paths") {
    performAllPaths(graph);
  } else if (algorithmName == "least-spanning-tree") {
    performLeastSpanningTree(graph);
  } else {
    View::displayErrorMessage("Unknown command: " + algorithmName);
  }
}

void Controller::handleInput(int argc, char *argv[]) {
  bool showHelp = false;
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--help") == 0) {
      showHelp = true;
      break;
    }
  }

  if (showHelp) {
    View::displayHelpMessage();
    return;
  }

  if (argc < 3) {
    View::displayUsageMessage();
    return;
  }

  std::string filename = argv[1];
  std::string algorithmName = argv[2];

  std::ifstream file(filename);
  if (!file.good()) {
    View::displayErrorMessage("File '" + filename + "' not found.");
    return;
  }

  try {
    Graph graph = _model.getGraph();
    graph.LoadGraphFromFile(filename);
    View::displaySuccessMessage("Graph loaded successfully.");
    graph.print();
    executeAlgorithm(graph, algorithmName, argc, argv);
  } catch (const std::exception &e) {
    View::displayErrorMessage(std::string("Error loading graph: ") + e.what());
  }
}
} // namespace s21