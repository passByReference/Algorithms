#include <iostream>
#include <fstream>
#include <list>
#include "Graph.h"

using namespace std;

void MST_Prim(Graph* g);


/*
 * A functor, or a function object, is an object that can behave like a function. This is done by defining operator()() of the class. 
 * In this case, implement operator()() as a comparison function
 *
 */
struct compVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.key > v2.key;
    }
};

int main() {
    ifstream infile("edges.txt");
    Graph* g = nullptr;
    if (infile.is_open()) {
        int V = 0;
        int E = 0;
        infile >> V >> E;
        g = new Graph(V);
        int start = 0;
        int end = 0;
        int weight = 0;
        while (infile >> start >> end >> weight) {
            g->addEdge(start - 1, end - 1, weight); 
        }
    }
    infile.close();

    MST_Prim(g);
    return 0;
}

Vertex* extractMin(list<Vertex*>& Q) {
    auto minV = Q.begin();
    auto minKey = (*minV)->key;
    for (auto iter = Q.begin(); iter != Q.end(); ++iter) {
        if ((*iter)->key < minKey) {
            minKey = (*iter)->key;
            minV = iter;
        }
    }
    Q.erase(minV);
    return *minV;
    
    
}

void MST_Prim(Graph* g) {
    if (g == nullptr) return;
    g->vertices[0].key = 0;
    list<Vertex*> Q;
    for (unsigned i = 0; i < g->vertices.size(); ++i) {
        Q.push_back(&g->vertices[i]);
    }
    long totalWeight = 0;
    while (!Q.empty()) {
      Vertex* u = extractMin(Q);
      totalWeight += u->key;
      u->isInQ = false;
      for (auto iter = u->adj.begin(); iter != u->adj.end(); ++iter) {
          auto& vertex = g->vertices.at(iter->first);
          if (vertex.isInQ && iter->second < vertex.key) {
              vertex.key = iter->second;
          }
      }
    }
    cout << "totalWeight = " << totalWeight << endl;
}

