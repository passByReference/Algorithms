//
// Created by Andy X on 3/26/17.
//

#ifndef CLUSTERING_UNIONFIND_H
#define CLUSTERING_UNIONFIND_H

class UnionFind {
public:
    UnionFind();
    void union(int p, int q);
    bool connected(int p, int q);

};

#endif //CLUSTERING_UNIONFIND_H
