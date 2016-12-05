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
#include "Graph.hpp"

class Dijkstra {
    int start, end;
    Graph mymap;
    std::priority_queue<vertex> vertex_heap;
    std::vector<float> dist;
    std::vector<vertex> prev;
public:
    Dijkstra(std::ifstream *map_file, int nodeStart, int nodeEnd);
    ~Dijkstra();
    void dijkstra();
};

#endif /* Dijkstra_hpp */
