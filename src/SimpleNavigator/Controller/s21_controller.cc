#include "s21_controller.h"

#include <cstring>
#include <fstream>
#include <string>

namespace s21 {

Controller::Controller(Model &model, View &view) : model_(model), view_(view) {}

void Controller::performDfs(Graph graph, int startVertex) {
  try {
    std::vector<int> result =
        model_.getGraphAlgorithms().DepthFirstSearch(graph, startVertex);
    View::displaySuccessMessage("DFS Result: ");
    View::printVector(result);
  } catch (const std::exception &e) {
    View::displayErrorMessage("Error performing DFS: " + std::string(e.what()));
  }
}

void Controller::performBfs(Graph graph, int startVertex) {
  try {
    std::vector<int> result =
        model_.getGraphAlgorithms().BreadthFirstSearch(graph, startVertex);
    View::displaySuccessMessage("BFS Result: ");
    View::printVector(result);
  } catch (const std::exception &e) {
    View::displayErrorMessage("Error performing BFS: " + std::string(e.what()));
  }
}

void Controller::performShortestPath(Graph graph, int firstVertex,
                                     int secondVertex) {
  try {
    size_t pathLength =
        model_.getGraphAlgorithms().GetShortestPathBetweenVertices(
            graph, firstVertex, secondVertex);
    View::displaySuccessMessage("Shortest Path Length: " +
                                std::to_string(pathLength));
  } catch (const std::exception &e) {
    View::displayErrorMessage("Error calculating shortest path: " +
                              std::string(e.what()));
  }
};

void Controller::performAllPaths(Graph graph) {
  try {
    matrix_t paths =
        model_.getGraphAlgorithms().GetShortestPathsBetweenAllVertices(graph);
    View::displaySuccessMessage("Shortest Paths Between All Vertices: ");
    View::printMatrix(paths);
  } catch (const std::exception &e) {
    View::displayErrorMessage("Error calculating all paths: " +
                              std::string(e.what()));
  }
};

void Controller::performLeastSpanningTree(Graph graph) {
  try {
    matrix_t lst = model_.getGraphAlgorithms().GetLeastSpanningTree(graph);
    View::displaySuccessMessage("Least Spanning Tree:\n");
    View::printMatrix(lst);
  } catch (const std::exception &e) {
    View::displayErrorMessage("Error calculating least spanning tree: " +
                              std::string(e.what()));
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

  if (showHelp || argc < 3) {
    View::displayHelpMessage();
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
    Graph graph = model_.getGraph();
    graph.LoadGraphFromFile(filename);
    View::displaySuccessMessage("Graph loaded successfully.");
    View::printMatrix(graph.GetMatrix());
    executeAlgorithm(graph, algorithmName, argc, argv);
  } catch (const std::exception &e) {
    View::displayErrorMessage(std::string("Error loading graph: ") + e.what());
  }
}
}  // namespace s21