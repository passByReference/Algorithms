#include "graph.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Graph::Graph() {
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];
    for (int i = 0; i < NODE_COUNT; ++i) {
        adjacencyMatrix[i] = new bool [NODE_COUNT];
        for (int j = 0; j < NODE_COUNT; ++j) {
            adjacencyMatrix[i][j] = false;
        }
    }
    for (int i = 0; i < NODE_COUNT; ++i) {
        markedVertices[i] = false;
    }

}

Graph::Graph(bool adjM[][NODE_COUNT]) {
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];
    for (int i = 0; i < NODE_COUNT; ++i) {
        for (int j = 0; j < NODE_COUNT; ++j) {
            adjacencyMatrix[i][j] = adjM[i][j];
        }
    }
    for (int i = 0; i < NODE_COUNT; ++i) {
        markedVertices[i] = false;
    }
}

Graph::~Graph() {
    for (int i = 0; i < NODE_COUNT; ++i) {
        delete [] adjacencyMatrix[i];
    }
    delete [] adjacencyMatrix;
    delete [] markedVertices;
}

bool Graph::createEdge(int u, int v) {
    if (!checkBoundary(u, v)) return false;
    adjacencyMatrix[u][v] = true;
    return true;
}

bool Graph::isAdjacent(int u, int v) {
    if (!checkBoundary(u, v)) return false;
    return adjacencyMatrix[u][v];
 
}

bool Graph::markVertex(int u) {
    if (!checkBoundary(u, 0)) return false;
    markedVertices[u] = true;
    return true;
}

bool Graph::isMarked(int u) {
    if (!checkBoundary(u, 0)) return false;
    return markedVertices[u];
}

void Graph:: unmarkAll() {
    for (int i = 0; i < NODE_COUNT; ++i) {
        markedVertices[i] = false;
    }
}

bool Graph::checkBoundary(int u, int v) {
    if (u < 0 || u >= NODE_COUNT) {
        cerr << "u = " << u << " out of range!" << endl;
        return false;
    }
    if (v < 0 || v >= NODE_COUNT) {
        cerr << "v = " << v << " out of range!" << endl;
        return false;
    }
    return true;
}

void Graph::BFS() {
   unmarkAll();
   queue<int> q;
   srand(time(NULL));
   int u = 0;
   cout << u << " ";
   if (markVertex(u)) {
       q.push(u);
       while (!q.empty()) {
           u = q.front();
           q.pop();
           for (int v= 0; v < NODE_COUNT; ++v) {
               if (isAdjacent(u, v) &&
                   (!isMarked(v))) {
                   markVertex(v);
                   cout << v << " ";
                   q.push(v);
               }
           }
       }
       cout << endl;
   }
   else return;
}

void Graph::DFS() {
    unmarkAll();
    int u = 2;
    DFS(u);
}
void Graph::DFS(int u) {
    cout << u << " ";
    if (markVertex(u)) {
        for (int v = 0; v < NODE_COUNT; ++v) {
            if (isAdjacent(u, v) &&
                    (!isMarked(v))) {
                DFS(v);
            }
        }
    }
    else return;
}
