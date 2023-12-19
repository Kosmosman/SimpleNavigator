//
// Created by joaquind on 17.12.23.
//
#include <gtest/gtest.h>

#include <unordered_map>

#include "s21_graph_algorithms.h"

using namespace s21;

struct TestcasesPrim {
    TestcasesPrim() {
        g3.LoadGraphFromFile("../res/3x3_d_test.txt");
        g5.LoadGraphFromFile("../res/5x5.txt");
        g10.LoadGraphFromFile("../res/10x10_d_test.txt");
        g15.LoadGraphFromFile("../res/15x15.txt");
    };

    struct Testcase {
        Graph &input;
        size_t want;
    };

    Graph g3{};
    Graph g5{};
    Graph g10{};
    Graph g15{};

    std::unordered_map<std::string, Testcase> testcase{
            {"Test 3x3", {g3, 2}},
            {"Test 5x5", {g5, 7}},
            {"Test 10x10", {g10, 11}},
            {"Test 15x15", {g15, 22}}
    };
};

TEST(PrimAlgo, PrimAlgoTest) {
    TestcasesPrim tk;
    auto path{[&](Graph &g) {
        auto path{0};
        for (auto &i: GraphAlgorithms::GetLeastSpanningTree(g)) {
            for (auto &j: i) {
                path += j;
            }
        }
        return path;
    }};
    for (auto &[name, test]: tk.testcase) {
        auto algo_path{path(test.input)};
        EXPECT_EQ(test.want, algo_path) << "Wrong answer in test \"" << name << "\"\n";
    }
}

