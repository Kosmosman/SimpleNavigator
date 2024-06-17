#include "s21_view.h"

using namespace s21;

const std::string MainView::kQuit = "q";

MainView::MainView() {}

int MainView::Start() {
  while (entered_symbol != kQuit) {
    PrintMenu();
    std::cin >> entered_symbol;
    StartFunctions();
    if (entered_symbol != kQuit) {
      std::cout << "Чтобы продолжить, нажмите клавишу \"Enter\"";
      std::cin.get();
      std::cin.get();
    } else {
      std::cout << "Thanks!";
    }
  }
  PrintLine();

  return 0;
}

void MainView::PrintMenu() {
  PrintLine();
  std::cout
      << " 1 - загрузка исходного графа из файла;\n"
         " 2 - обход графа в ширину с выводом результата обхода в консоль;\n"
         " 3 - обход графа в глубину с выводом результата обхода в консоль;\n"
         " 4 - поиск кратчайшего пути между произвольными двумя вершинами с "
         "выводом результата в консоль;\n"
         " 5 - поиск кратчайших путей между всеми парами вершин в графе с "
         "выводом результирующей матрицы в консоль;\n"
         " 6 - поиск минимального остовного дерева в графе с выводом "
         "результирующей матрицы смежности в консоль;\n"
         " 7 - решение задачи комивояжера с выводом результирующего маршрута и "
         "его длины в консоль\n"
         " q - выйти.";
  PrintLine();
}

void MainView::PrintLine() {
  std::cout << "\n-------------------------------------------------------------"
               "---------\n";
}

void MainView::StartFunctions() {
  std::istringstream num_str_iss(entered_symbol);
  unsigned query_num = 0;
  num_str_iss >> query_num;

  if (query_num == 1) {
    LoadGraphFromFile();
  } else if (query_num == 2) {
    // BreadthFirstSearch();
  } else if (query_num == 3) {
    // DeepFirstSearch();
  } else if (query_num == 4) {
    // GetShortestPathBetweenVertices();
  } else if (query_num == 5) {
    //  GetShortestPathsBetweenAllVertices();
  } else if (query_num == 6) {
    //  GetLeastSpanningTree();
  } else if (query_num == 7) {
    // SolveTravelingSalesmanProblem();
  }
}

void MainView::LoadGraphFromFile() {
  std::cout << "Введите путь к файлу графика: ";
  std::cin >> path_;
  // ModelLoadGraphFromFile(path_);
  std::cout << "Исходный график из файла:\n";
  // matrix_ = ModelGetAdjacencyMatrix();
  PrintMatrix();
}

void MainView::PrintMatrix() {
  for (auto i = 0U; i < matrix_.size(); i++) {
    vector_ = matrix_[i];
    PrintVector(' ');
  }
}

void MainView::PrintVector(char delimiter) {
  for (auto j = 0U; j < vector_.size(); j++) {
    if (delimiter == ' ') {
      std::cout.width(4);
    }
    std::cout << vector_[j];
    if (j < vector_.size() - 1) {
      std::cout << delimiter;
    }
  }
  std::cout << "\n";
}
