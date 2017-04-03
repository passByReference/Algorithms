#!/usr/bin/env python
from Graph import Graph
from Vertex import Vertex
import sys

def main():
    infile = open('dijkstra.txt', 'r')
    lines = infile.readlines()
    records = [line.rstrip('\n\r').split() for line in lines]
    g = Graph()
    for record in records:
        for u in record[1:]:
            u = u.split(',')
            g.addEdge(int(record[0]), int(u[0]), int(u[1]))
    dijkstra(g, g.vertices[1])

def initializeSingleSource(graph, s):
    for v in graph.vertices:
        graph.vertices[v].d = sys.maxsize
        graph.vertices[v].prev = None
    s.d = 0
    s.prev = None
    
def relax(u, v): # pass by reference
    print("relax u.d: ", u.d, " v.d: ", v.d)
    if v.d > u.d + u.adj[v.val]:
        v.d = u.d + u.adj[v.val]
        print("relax v.d: ", v.d)
        v.prev = u

def extractMin(Q): # pass by reference
    if len(Q) > 1:
        i = iter(Q)
        minV = Q[next(i)]
        minD = minV.d
        for v in Q:
            if Q[v].d < minD:
                minD = Q[v].d
                minV = Q[v]
        del Q[minV.val]
        return minV
    else:
        for v in Q.values():
            minV = v
            del Q[minV.val]
            return minV
        
def dijkstra(graph, s):
    initializeSingleSource(graph, s) # works
    S = []
    Q = graph.vertices
    while len(Q) > 0:
        u = extractMin(Q)
        S.append(u)
        for v in u.adj:
            if v in Q:
                relax(u, Q[v])
    
main()

