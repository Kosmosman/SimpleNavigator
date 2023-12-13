#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "Graph.h"

TEST(GraphTest, LoadGraphFromFileTest) {
  s21::Graph graph;

  graph.LoadGraphFromFile("3x3.txt");

  const auto& matrix = graph.GetMatrix();
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
  s21::Graph graph;

  graph.SetMatrix({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});

  graph.ExportGraphToDot("testGraph.dot");

  std::ifstream dotFile("testGraph.dot");
  std::stringstream dotBuffer;
  dotBuffer << dotFile.rdbuf();
  dotFile.close();

  std::string expectedOutput =
      "graph G {\n 0 -- 1;\n 0 -- 2;\n 1 -- 3;\n 1 -- 4;\n 1 -- 5;\n 2 -- 6;\n "
      "2 -- 7;\n 2 -- 8;\n}\n";
  EXPECT_EQ(dotBuffer.str(), expectedOutput);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}