//
//  Dijkstra.hpp
//  lab6
//
//  Created by Joseph Marshall on 12/4/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#ifndef Dijkstra_hpp
#define Dijkstra_hpp

#include <queue>
#include <fstream>
#include <string>
#include <iostream>
#include <limits>
#include "Graph.hpp"

class Dijkstra {
    int start, end;
    Graph graph;
    std::map<int, float> dist;
    std::map<int, vertex *> prev;
    std::vector<vertex *> shortestPath;
    std::map<vertex *, float, ptr_less> min_heap;
public:
    float finalDistance;
    std::vector<edge *> finalPrintout;
    Dijkstra(std::ifstream *map_file, int nodeStart, int nodeEnd);
    std::vector<vertex *> toDelete;
    ~Dijkstra();
    void dijkstra();
    void print();
    edge * sharedEdge(vertex *a, vertex *b);
};

#endif /* Dijkstra_hpp */
