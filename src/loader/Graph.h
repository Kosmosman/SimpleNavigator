//
// Created by joaquind on 13.12.23.
//

#ifndef SIMPLENAVIGATOR_GRAPH_H
#define SIMPLENAVIGATOR_GRAPH_H

#include <string>
#include <vector>

namespace s21 {

    class Graph {
    public:
        Graph()=default;
        void LoadGraphFromFile(std::string filename);
        void ExportGraphToDot(std::string filename);

    private:
        std::vector<std::vector<int>> matrix_{};
    };

} // s21

#endif //SIMPLENAVIGATOR_GRAPH_H
