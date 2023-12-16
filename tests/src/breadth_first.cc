#include <gtest/gtest.h>

#include "s21_graph_algorithms.h"

using namespace s21;

struct TestcasesBFS {
  TestcasesBFS() {
    g3.LoadGraphFromFile("../res/3x3_d_test.txt");
    g5.LoadGraphFromFile("../res/5x5.txt");
    g10.LoadGraphFromFile("../res/10x10_d_test.txt");
    tests = {{"Matrix 3x3", {g3, tk3x3}},
             {"Matrix 5x5", {g5, tk5x5}},
             {"Matrix 10x10", {g10, tk10x10}}};
  }

  struct Testcase {
    Graph input_graph;
    std::vector<int> expected_result{};
  };

  Graph g3{};
  Graph g5{};
  Graph g10{};

  std::vector<int> tk3x3{0, 1, 2};
  std::vector<int> tk5x5{0, 1, 2, 3, 4};
  std::vector<int> tk10x10{
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
  };

  std::unordered_map<std::string, Testcase> tests{};
};

TEST(BreadthFirstSearch, BFITestMatrix3x3) {
  TestcasesBFS t;
  auto res{GraphAlgorithms::BreadthFirstSearch(
      t.tests["Matrix 3x3"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 3x3"].expected_result)
      << "Wrong answer in test \"Matrix 3x3\".";
}

TEST(BreadthFirstSearch, BFITestMatrix5x5) {
  TestcasesBFS t;
  auto res{GraphAlgorithms::BreadthFirstSearch(
      t.tests["Matrix 5x5"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 5x5"].expected_result)
      << "Wrong answer in test \"Matrix 5x5\".";
}

TEST(BreadthFirstSearch, BFITestMatrix10x10) {
  TestcasesBFS t;
  auto res{GraphAlgorithms::BreadthFirstSearch(
      t.tests["Matrix 10x10"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 10x10"].expected_result)
      << "Wrong answer in test \"Matrix 10x10\".";
}
