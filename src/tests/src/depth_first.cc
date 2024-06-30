#include <gtest/gtest.h>

#include "../../GraphAlgorithms/s21_graph_algorithms.h"

using namespace s21;

struct TestcasesDFS {
  TestcasesDFS() {
    g3.LoadGraphFromFile("../res/3x3_d_test.txt");
    g5.LoadGraphFromFile("../res/5x5_depth.txt");
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
  std::vector<int> tk5x5{0, 1, 2, 4, 3};
  std::vector<int> tk10x10{
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
  };

  std::unordered_map<std::string, Testcase> tests{};
};

TEST(DepthFirstSearch, DFITestMatrix3x3) {
  TestcasesDFS t;
  auto res{
      GraphAlgorithms::DepthFirstSearch(t.tests["Matrix 3x3"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 3x3"].expected_result)
      << "Wrong answer in test \"Matrix 3x3\".";
}

TEST(DepthFirstSearch, DFITestMatrix5x5) {
  TestcasesDFS t;
  auto res{
      GraphAlgorithms::DepthFirstSearch(t.tests["Matrix 5x5"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 5x5"].expected_result)
      << "Wrong answer in test \"Matrix 5x5\".";
}

TEST(DepthFirstSearch, DFITestMatrix10x10) {
  TestcasesDFS t;
  auto res{GraphAlgorithms::DepthFirstSearch(
      t.tests["Matrix 10x10"].input_graph, 0)};
  EXPECT_EQ(res, t.tests["Matrix 10x10"].expected_result)
      << "Wrong answer in test \"Matrix 10x10\".";
}
