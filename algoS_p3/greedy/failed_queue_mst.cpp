#include <iostream>
#include <queue>
#include <fstream>
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
    /*
    bool error = false;
    for (auto& v : g->vertices) {
        if (v.val >= 500) {
            cout << "error! " << v.val << endl;
            error = true;
            break;
        }
        cout << "vertex val: " << v.val << endl;
        cout << "edges " << endl;
        for (auto& e : v.adj) {
            if (e.first >= 500) {
                cout << "error in e! " << e.first << endl;
                error = true;
                break;
            }
            cout << v.val << "->" << e.first << " with weight = " << e.second << endl;
        }
    }
    if (error) cout << " there is an error" << endl;
    */
    MST_Prim(g);
    return 0;
}

void MST_Prim(Graph* g) {
    if (g == nullptr) return;
    g->vertices[0].key = 0;
    priority_queue<Vertex, vector<Vertex>, compVertex> q(g->vertices.begin(), g->vertices.end());
    while (!q.empty()) {
      Vertex& u = const_cast<Vertex&>(q.top());
      cout << u.val << " " << u.key << endl;
      g->vertices[u.val].isInQ = false;
      u.isInQ = false;
      q.pop();
      cout << "Im here" << endl;
      for (auto iter = u.adj.begin(); iter != u.adj.end(); ++iter) {
//          cout << "entering loop " << endl;
          // iter could be invalid, which'd cause a seg fault...don't know why
          if (iter != u.adj.end()&& iter->first >= 500) continue;
//          cout << "u.val: " << u.val << endl;
//          cout <<" v.first: " << iter->first <<" v.second: " << iter->second << endl;
          auto& vertex = g->vertices.at(iter->first);
//          cout << "after at" << endl;
          if (vertex.isInQ && iter->second < vertex.key) {
              vertex.key = iter->second;
              /*
               * The problem here is we need to update the key of vertex in the priority_queue,
               * but C++ doesn't provide a iterating mechanism for queues. 
               *
               * The code below will not work
               */
              auto vertexQ = find(q.begin(), q.end(), vertex.val);
              vertexQ->key = iter->second;
          }
//          cout << "finished loop" << endl;
      }
      cout << "Im out " << endl;

    }

    for (auto& u : g->vertices) {
        cout << u.key << endl;
    }
}

