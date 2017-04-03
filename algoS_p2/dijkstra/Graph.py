#!/usr/bin/env python
from Vertex import Vertex

class Graph:
    def __init__(self):
        self.vertices = {}
        self.E = 0

    def addEdge(self, start, end, weight):
        try:
            if start not in self.vertices:
                v = Vertex(start)
                self.vertices[start] = v
            if end not in self.vertices:
                v = Vertex(end)
                self.vertices[end] = v
            self.vertices[start].adj[end] = weight
            self.E += 1
        except:
            print("Error in addEdge()")

    def printVertices(self):
        for v in self.vertices:
            print(v, ' v.d: ', self.vertices[v].d)



