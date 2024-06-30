#ifndef A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_
#define A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_

#include <iostream>
#include <string>

#include "../../Graph/s21_graph.h"

namespace s21 {
class View {
 public:
  View() = default;
  static void printMatrix(matrix_t graphMatrix);
  static void displayHelpMessage();
  static void displayUsageMessage();
  static void displaySuccessMessage(const std::string &message);
  static void displayErrorMessage(const std::string &message);
};
}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_
