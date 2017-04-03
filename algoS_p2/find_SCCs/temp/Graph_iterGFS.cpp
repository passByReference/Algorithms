#include "Graph.h"
#include <iostream>
#include <stack>

Graph::Graph() {
    vertices = std::vector<Vertex>(V);
}

void Graph::addEdge(int start, int end) {
    try {
        if (vertices[start].val == -1) vertices[start].val = start;
        if (vertices[end].val == -1) vertices[end].val = end;
        vertices[start].adj.push_back(end);
        ++E;
    } catch (...) {
        std::cout << "in catch" << std::endl;
    }
   
}

std::vector<int>& Graph::getAdj(int v) {
    return vertices.at(v).adj;
}

void Graph::DFS() {
    for (auto vertex : vertices) {
        vertex.visited = false;
        vertex.d = 0;
        vertex.f = 0;
    }

    int time = 0;

    Vertex* currVertex = &vertices[0];
    std::stack<Vertex* > toVisit;
    toVisit.push(currVertex);
    while (!toVisit.empty()) {
        currVertex = toVisit.top();
        toVisit.pop();
        if (!currVertex->visited) {
            currVertex->visited = true;
            currVertex->d = ++time;
            for (int i = 0; i < currVertex->adj.size(); ++i) {
                toVisit.push(&vertices[currVertex->adj[i]]);
            }
        } else {
            if (currVertex->d != 0) currVertex->f = ++time;
        }
    }


}
void Graph::DFS(int v) {
    Vertex* currVertex = &vertices[v];
    std::stack<Vertex* > toVisit;
    toVisit.push(currVertex);
    while (!toVisit.empty()) {
        currVertex = toVisit.top();
        toVisit.pop();
        if (!currVertex->visited) {
            currVertex->visited = true;
            std::cout << currVertex->val << std::endl;
            for (int i = 0; i < currVertex->adj.size(); ++i) {
                toVisit.push(&vertices[currVertex->adj[i]]);
            }
        }
    }
}

void Graph::printVertices() {
    
    for (auto vertex : vertices) {
        std::cout << "vertex val : " << vertex.val << std::endl;
        std::cout << "vertex d   : " << vertex.d   << std::endl;
        std::cout << "vertex f   : " << vertex.f   << std::endl;
    }

}
