// model/s21_model.cc
#include "s21_model.h"

namespace s21 {
Model::Model() : _graph(), _graphAlgorithms() {}

Model::~Model() {}

Graph &Model::getGraph() { return _graph; }

void Model::setGraph(const Graph &graph) { _graph = graph; }

GraphAlgorithms &Model::getGraphAlgorithms() { return _graphAlgorithms; }
}  // namespace s21
