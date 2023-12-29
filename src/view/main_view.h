#ifndef A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_
#define A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_

#include <iostream>
#include <sstream>
#include <vector>

namespace s21 {
class MainView {
public:
  MainView();

  int Start();

private:
  void StartFunctions();
  void LoadGraphFromFile();
  void PrintMenu();
  void PrintLine();
  void PrintMatrix();
  void PrintVector(char delimiter);

  static const std::string kQuit;
  std::string entered_symbol{};
  std::string path_{};
  std::vector<std::vector<unsigned>> matrix_;
  std::vector<unsigned> vector_;
};
} // namespace s21

#endif // A2_SIMPLENAVIGATOR_SRC_VIEW_MAIN_VIEW_H_
