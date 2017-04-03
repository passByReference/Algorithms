#include<iostream>
#include<fstream>
#include<string>
#include "Graph.h"
using namespace std;

int main() {
    ifstream infile("SCC.txt");
    Graph g = Graph();
    if (infile.is_open()) {
        int start = 0;
        int end = 0;
        while (infile >> start >> end) {
            //cout << start <<", " << end << endl;
            g.addEdge(start - 1, end - 1);
        }
        cout << "total number of edges = " << g.getE() << endl;
        g.DFS();
        //g.printVertices();
        g.transpose();
        //g.printVertices_T();
        g.DFS_T();
        /*
        auto result = g.getAdj(10);
        for (auto& v : result) {
            cout << v << endl;
        }
        cout << "================" << endl;
        auto result2 = g.getAdj_T(4);
        for (auto& v : result2) {
            cout << v << endl;
        }
        */
    }
    infile.close();

    return 0;
}
