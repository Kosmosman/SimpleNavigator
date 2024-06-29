// model/s21_model.h
#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include "../../Graph/s21_graph.h"
#include "../../GraphAlgorithms/s21_graph_algorithms.h"

namespace s21 {
class Model {
public:
  Model();
  ~Model();

  Graph &getGraph();
  void setGraph(const Graph &graph);
  GraphAlgorithms &getGraphAlgorithms();

private:
  Graph _graph;
  GraphAlgorithms _graphAlgorithms;
};
} // namespace s21

#endif // S21_MODEL_H_
