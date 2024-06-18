#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "s21_graph.h"

using namespace s21;

TEST(GraphTest, LoadGraphFromFileTest) {
  Graph graph;

  graph.LoadGraphFromFile("../res/3x3.txt");

  const auto &matrix = graph.GetMatrix();
  EXPECT_EQ(matrix[0][0], 0);
  EXPECT_EQ(matrix[0][1], 1);
  EXPECT_EQ(matrix[0][2], 2);
  EXPECT_EQ(matrix[1][0], 3);
  EXPECT_EQ(matrix[1][1], 4);
  EXPECT_EQ(matrix[1][2], 5);
  EXPECT_EQ(matrix[2][0], 6);
  EXPECT_EQ(matrix[2][1], 7);
  EXPECT_EQ(matrix[2][2], 8);
}

TEST(GraphTest, ExportGraphToDotTest) {
  Graph graph;

  graph.LoadGraphFromFile("../res/4x4.txt");

  graph.ExportGraphToDot("../res/testGraph.dot");

  std::ifstream dotFile("../res/testGraph.dot");
  std::stringstream dotBuffer;
  dotBuffer << dotFile.rdbuf();
  dotFile.close();

  std::string expectedOutput =
      "graph {\n0 -- 1;\n1 -- 0;\n1 -- 2;\n1 -- 3;\n2 -- 1;\n3 -- 1;\n}\n";
  EXPECT_EQ(dotBuffer.str(), expectedOutput);
}
