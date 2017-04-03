#include <iostream>
#include <queue>

const int NODE_COUNT = 10;


class Graph
{

public:

	Graph(); // constructor
	~Graph(); // destructor
	

	Graph(bool adjM[][NODE_COUNT]);

	bool createEdge(int u, int v);

	bool isAdjacent(int u, int v);

	bool markVertex(int u);

	bool isMarked(int u);

	void unmarkAll();

	void BFS();

	void DFS();

private:
	void DFS(int vertex);
        bool checkBoundary(int u, int v);
	bool *markedVertices;
	bool **adjacencyMatrix;



};

