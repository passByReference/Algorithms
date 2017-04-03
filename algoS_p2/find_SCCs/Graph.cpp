#include "Graph.h"
#include <iostream>
#include <stack>
#include <typeinfo>


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

std::vector<int>& Graph::getAdj_T(int v) {
    return vertices_T.at(v).adj;
}
void Graph::DFS_T() {
    vertices_T_Orig = std::vector<Vertex>(vertices_T);
    
    //for (auto v : vertices_T_Orig) std::cout << v.val << ", f: " << v.f << ", color: " << v.color <<std::endl;
    std::sort(vertices_T.begin(), vertices_T.end(), compare);
    std::cout << "sorted" << std::endl;
    std::vector<int> SCC_sizes;

    for (auto& vertex : vertices_T) { // use auto& vertex instead of auto vertex,
                                    // the latter creates a copy of vertex
        if (vertices_T_Orig[vertex.val].color == 0) {
            //std::cout << "Im here" << std::endl;
            auto result = DFS_T_helper(&vertices_T_Orig[vertex.val]);
            SCC_sizes.push_back(result);
        }
        
    }
    std::sort(SCC_sizes.begin(), SCC_sizes.end());
    for (auto iter = SCC_sizes.cbegin(); iter != SCC_sizes.cend(); ++iter) {
        std::cout << *iter << std::endl;
    }
    
}
int Graph::DFS_T_helper(Vertex* vertex) {
    std::stack<Vertex* > toVisit;
    Vertex* currVertex = vertex;
    toVisit.push(currVertex);

    int counter = 0; // counts number of component
    while (!toVisit.empty()) {
        currVertex = toVisit.top();
        //std::cout << "val: " << currVertex->val << " color: " << currVertex->color << " d: " << currVertex->d << " f: " << currVertex->f << std::endl;
        if (currVertex->color == 2) toVisit.pop();// Possibly, a vertex would be added to the stack 
                                                  // more than once, hence an existing vertex in the 
                                                  // stack could be 2, as it has been updated 
                                                  // and poped off previously
        if (currVertex->color == 1) {
            currVertex->color = 2;
            ++counter;
            toVisit.pop();
            continue;
        }
        if (currVertex->color == 0) {
            currVertex->color = 1;
        }
        for (unsigned i = 0; i < currVertex->adj.size(); ++i) {
            //std::cout << "currVertex val: " << currVertex->val << ", adj: " << currVertex->adj[i] << std::endl;
            if (vertices_T_Orig[currVertex->adj[i]].color == 0) {
                //std::cout << "adj vertex " << vertices_T_Orig[currVertex->adj[i]].val << std::endl;
                toVisit.push(&vertices_T_Orig[currVertex->adj[i]]);
            }
        }
    }
    return counter;
}


void Graph::DFS() {
    for (auto& vertex : vertices) {
        vertex.color = 0;
        vertex.d = 0;
        vertex.f = 0;
    }

    timeCounter = 0;

    for (auto& vertex : vertices) { // use auto& vertex instead of auto vertex,
                                    // the latter creates a copy of vertex
        if (vertex.color == 0) {
            //std::cout << "Im here" << std::endl;
            DFS_helper(&vertex);
        }
        
    }
}

void Graph::DFS_helper(Vertex* vertex) {
    std::stack<Vertex* > toVisit;
    Vertex* currVertex = vertex;
    toVisit.push(currVertex);
    
    while (!toVisit.empty()) {
        currVertex = toVisit.top();
        //std::cout << "val: " << currVertex->val << " color: " << currVertex->color << " d: " << currVertex->d << " f: " << currVertex->f << std::endl;
        if (currVertex->color == 2) toVisit.pop();// Possibly, a vertex would be added to the stack 
                                                  // more than once, hence an existing vertex in the 
                                                  // stack could be 2, as it has been updated 
                                                  // and poped off previously
        if (currVertex->color == 1) {
            currVertex->color = 2;
            currVertex->f = ++timeCounter;
            toVisit.pop();
            continue;
        }
        if (currVertex->color == 0) {
            currVertex->color = 1;
            currVertex->d = ++timeCounter;
        }
        for (unsigned i = 0; i < currVertex->adj.size(); ++i) {
            if (vertices[currVertex->adj[i]].color == 0) {
                toVisit.push(&vertices[currVertex->adj[i]]);
            }
        }
    }
}

void Graph::transpose() {
    vertices_T = std::vector<Vertex>(V); 
    for (unsigned i = 0; i < vertices.size(); ++i) {
        vertices_T[i].val = vertices[i].val;
        vertices_T[i].d = vertices[i].d;
        vertices_T[i].f = vertices[i].f;
    }
    for (const auto& vertex : vertices) {
        for (const auto& newStart : vertex.adj) {
            vertices_T[newStart].adj.push_back(vertex.val);
        }
    }
    /*
    for (auto& v : vertices_T){
        std::cout << "val: " << v.val << " d: " << v.d << " f: " << v.f << " adj size: " << v.adj.size() << std::endl;
    }
    */

}

void Graph::printVertices() {
    std::cout << "printVertices" << std::endl;
    for (const auto& vertex : vertices) {
        std::cout << "vertex val : " << vertex.val << " d: " << vertex.d << " f: " << vertex.f << std::endl;
        for (const auto& e : vertex.adj) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void Graph::printVertices_T() {
    std::cout << "printVertices_T" << std::endl;
    for (const auto& vertex : vertices_T) {
        std::cout << "vertex val : " << vertex.val << " d: " << vertex.d << " f: " << vertex.f << std::endl;
        for (const auto& e : vertex.adj) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}
