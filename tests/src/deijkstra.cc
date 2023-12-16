//
// Created by joaquind on 14.12.23.
//
#include <gtest/gtest.h>

#include <unordered_map>

#include "s21_graph_algorithms.h"

using namespace s21;

struct Testcases {
  Testcases() {
    g10.LoadGraphFromFile("../res/10x10_d_test.txt");
    g3.LoadGraphFromFile("../res/3x3_d_test.txt");
  }

  struct Testcase {
    std::pair<int, int> input;
    size_t want;
  };

  Graph g3{};
  std::unordered_map<std::string, Testcase> tk3x3{
      {"Test 3 vertexes: 2-1", {std::make_pair(2, 1), 3}},
      {"Test 3 vertexes: 1-3", {std::make_pair(1, 3), 1}},
      {"Test 3 vertexes: 3-1", {std::make_pair(3, 1), 2}},
      {"Test 3 vertexes: 2-3", {std::make_pair(2, 3), 1}}};

  Graph g10{};
  std::unordered_map<std::string, Testcase> tk10x10{
      {"Test 10 vertexes: 1-5", {std::make_pair(1, 5), 5}},
      {"Test 10 vertexes: 1-9", {std::make_pair(1, 9), 2}},
      {"Test 10 vertexes: 3-7", {std::make_pair(3, 7), 3}},
      {"Test 10 vertexes: 6-2", {std::make_pair(6, 2), 6}},
      {"Test 10 vertexes: 4-9", {std::make_pair(4, 9), 3}},
      {"Test 10 vertexes: 10-1", {std::make_pair(10, 1), 5}},
      {"Test 10 vertexes: 3-6", {std::make_pair(3, 6), 3}},
  };
};

TEST(ShortestWay, DeijkstraAlgoTest3x3) {
  Testcases tk;
  for (auto &[test_name, testcase] : tk.tk3x3) {
    auto res{GraphAlgorithms::GetShortestPathBetweenVertices(
        tk.g3, testcase.input.first, testcase.input.second)};
    EXPECT_EQ(res, testcase.want) << "Wrong answer in test \"" << test_name;
  }
}

TEST(ShortestWay, DeijkstraAlgoTest10x10) {
  Testcases tk;
  for (auto &[test_name, testcase] : tk.tk10x10) {
    auto res{GraphAlgorithms::GetShortestPathBetweenVertices(
        tk.g10, testcase.input.first, testcase.input.second)};
    EXPECT_EQ(res, testcase.want) << "Wrong answer in test \"" << test_name;
  }
}
