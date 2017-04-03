#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <fstream>

struct Vertex {
    int val;
    int d; // discoverd time
    int f; // finished time;
    int color; //0-white, 1-grey, 2-black
    std::vector<int> adj; // adjacency list
    
    Vertex() : val(-1), d(0), f(0), color(0) {};
    Vertex(int v) : val(v), d(0), f(0), color(0) {};
};
class Graph {
    public:
        Graph();
        void addEdge(int start, int end);
        std::vector<int>& getAdj(int v);
        std::vector<int>& getAdj_T(int v);
        inline int getE() const{return E;};
        inline int getV() const {return V;};
        inline Vertex& getVertex(int v) {return vertices[v];};

        void DFS_T();
        int DFS_T_helper(Vertex* vertex);

        void DFS();
        void DFS_helper(Vertex* vertex);
        void transpose();

        void printVertices();
        void printVertices_T();
    private:
        std::vector<Vertex> vertices;
        std::vector<Vertex> vertices_T; // stores transposed graph
        std::vector<Vertex> vertices_T_Orig; // stores transposed graph
        int E; // number of edges
        // static const int V = 875714; // number of vertices
        static const int V = 875714; // number of vertices
        //static const int V = 12; // number of vertices
        int timeCounter = 0;
        std::ofstream outfile;

        inline static bool compare(const Vertex& v1, const Vertex& v2) {return v1.f > v2.f;}
};

#endif
