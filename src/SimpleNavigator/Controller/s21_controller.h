#ifndef A2_SIMPLENAVIGATOR_SRC_CONTROLLER_MAIN_CONTROLLER_H_
#define A2_SIMPLENAVIGATOR_SRC_CONTROLLER_MAIN_CONTROLLER_H_

#include "../Model/s21_model.h"
#include "../View/s21_view.h"

namespace s21 {
class Controller {
 public:
  Controller(Model &model, View &view);
  void handleInput(int argc, char *argv[]);

 private:
  Model &_model;
  View &_view;

  void performDfs(Graph graph, int startVertex);
  void performBfs(Graph graph, int startVertex);
  void performShortestPath(Graph graph, int firstVertex, int secondVertex);
  void performAllPaths(Graph graph);
  void performLeastSpanningTree(Graph graph);

  void executeAlgorithm(Graph &graph, const std::string &algorithmName,
                        int argc, char *argv[]);
};
}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_CONTROLLER_MAIN_CONTROLLER_H_