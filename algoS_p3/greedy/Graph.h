#ifndef GRAPH_H_
#define GRAPH_H_

#include <unordered_map>
#include <fstream>
#include <vector>
#include <climits>

struct Vertex {
    int val;
    int key; // min weight of any vertex connecting v to a vertex in MST
    std::unordered_map<int, int> adj; // adjacency list of vertex val : weight
    bool isInQ;
    Vertex() : val(-1), key(INT_MAX), isInQ(true) {};
    Vertex(int v) : val(v), key(INT_MAX), isInQ(true) {};
};
class Graph {
    public:
        Graph(int V);
        void addEdge(int start, int end, int weight);
        std::unordered_map<int, int>& getAdj(int v);
        std::vector<Vertex> vertices;

};

#endif
