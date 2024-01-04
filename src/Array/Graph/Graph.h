//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//
//


#include "../../General/AbstractGraph.h"

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        Path* dijkstra(int source);
        int **getEdges();

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;

    };

}

