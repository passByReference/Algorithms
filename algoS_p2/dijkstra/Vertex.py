#!/usr/bin/env python
class Vertex:
    def __init__(self, val):
        self.val = val;
        self.dt = 0 # discovery time
        self.ft = 0 # finish time
        self.color = 0 # 0-white, 1-gray, 2-black
        self.d = 0 # distance
        self.prev = None
        self.adj = {} # key: vertex.val, value: distance/weight from self to the vertex 


