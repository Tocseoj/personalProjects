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
    //struct heap_entry {
    //    float distance;
    //    vertex *v;
    //    heap_entry(float d, vertex *vp) {
    //        distance = d;
    //        v = vp;
    //    }
    //    struct compare {
    //        bool operator()(const heap_entry *left, const heap_entry *right) {
    //            return left->distance > right->distance;
    //        }
    //    };
    //};
    std::map<vertex *, float, ptr_less> min_heap;
public:
    float finalDistance;
    std::vector<edge *> finalPrintout;
    Dijkstra(std::ifstream *map_file, int nodeStart, int nodeEnd);
    ~Dijkstra();
    void dijkstra();
    //void decreaseKey(vertex *v, float newDist);
    void print();
    edge * sharedEdge(vertex *a, vertex *b);
};

#endif /* Dijkstra_hpp */
