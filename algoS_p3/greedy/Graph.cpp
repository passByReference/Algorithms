#include "Graph.h"
#include <iostream>
#include <stack>
#include <typeinfo>


Graph::Graph(int V) {
    vertices = std::vector<Vertex>(V);
}

void Graph::addEdge(int start, int end, int weight) {
    try {
        if (vertices[start].val == -1) vertices[start].val = start;
        if (vertices[end].val == -1) vertices[end].val = end;
        vertices[start].adj[end] = weight;
        vertices[end].adj[start] = weight; // remember to udpate end-start edge when operating on undirected graphs
    } catch (...) {
        std::cout << "in catch" << std::endl;
    }
   
}

std::unordered_map<int, int>& Graph::getAdj(int v) {
    return vertices.at(v).adj;
}


