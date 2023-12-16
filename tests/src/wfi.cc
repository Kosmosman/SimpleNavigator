//
// Created by joaquind on 15.12.23.
//
#include <gtest/gtest.h>

#include <unordered_map>

#include "s21_graph_algorithms.h"

using namespace s21;

struct TestcasesWFI {
  TestcasesWFI() {
    g3.LoadGraphFromFile("../res/3x3_d_test.txt");
    g5.LoadGraphFromFile("../res/5x5.txt");
    g10.LoadGraphFromFile("../res/10x10_d_test.txt");
    tests = {{"Matrix 3x3", {g3, tk3x3}},
             {"Matrix 5x5", {g5, tk5x5}},
             {"Matrix 10x10", {g10, tk10x10}}};
  }

  struct Testcase {
    Graph input_graph;
    matrix_t expected_result{};
  };

  Graph g3{};
  Graph g5{};
  Graph g10{};

  matrix_t tk3x3{{0, 1, 1}, {3, 0, 1}, {2, 1, 0}};
  matrix_t tk5x5{{0, 6, 7, 2, 5},
                 {8, 0, 4, 6, 2},
                 {14, 6, 0, 2, 8},
                 {12, 4, 8, 0, 6},
                 {9, 1, 2, 4, 0}};

  matrix_t tk10x10{{0, 3, 5, 6, 5, 3, 5, 6, 2, 7},
                   {1, 0, 2, 3, 6, 4, 3, 4, 3, 4},
                   {2, 5, 0, 1, 6, 3, 3, 2, 4, 2},
                   {3, 5, 4, 0, 7, 2, 2, 6, 3, 6},
                   {3, 6, 1, 2, 0, 4, 3, 1, 5, 3},
                   {3, 6, 4, 5, 5, 0, 3, 6, 1, 6},
                   {4, 3, 2, 3, 6, 1, 0, 4, 2, 4},
                   {6, 6, 5, 6, 8, 3, 6, 0, 4, 5},
                   {2, 5, 4, 5, 4, 4, 3, 5, 0, 6},
                   {5, 4, 3, 4, 4, 2, 1, 4, 3, 0}

  };

  std::unordered_map<std::string, Testcase> tests{};
};

TEST(ShortestWayForAllVertexes, WFITestMatrix3x3) {
  TestcasesWFI t;
  auto res{GraphAlgorithms::GetShortestPathsBetweenAllVertices(
      t.tests["Matrix 3x3"].input_graph)};
  EXPECT_EQ(res, t.tests["Matrix 3x3"].expected_result)
      << "Wrong answer in test \"Matrix 3x3\".";
}

TEST(ShortestWayForAllVertexes, WFITestMatrix5x5) {
  TestcasesWFI t;
  auto res{GraphAlgorithms::GetShortestPathsBetweenAllVertices(
      t.tests["Matrix 5x5"].input_graph)};
  EXPECT_EQ(res, t.tests["Matrix 5x5"].expected_result)
      << "Wrong answer in test \"Matrix 5x5\".";
}

TEST(ShortestWayForAllVertexes, WFITestMatrix10x10) {
  TestcasesWFI t;
  auto res{GraphAlgorithms::GetShortestPathsBetweenAllVertices(
      t.tests["Matrix 10x10"].input_graph)};
  EXPECT_EQ(res, t.tests["Matrix 10x10"].expected_result)
      << "Wrong answer in test \"Matrix 10x10\".";
}
