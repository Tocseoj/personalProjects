//
//  Astar.hpp
//  lab6
//
//  Created by Joseph Marshall on 12/5/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#ifndef Astar_hpp
#define Astar_hpp

#include <set>
#include <fstream>
#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include "Graph.hpp"

class Astar {
    int start, end;
    Graph graph;
    std::set<vertex *, ptr_less> openSet;
    std::set<vertex *, ptr_less> closedSet;
    std::map<int, vertex *> cameFrom;
    std::vector<vertex *> shortestPath;
    std::map<vertex *, float, ptr_less> gScore;
    std::map<vertex *, float, ptr_less> fScore;
public:
    float finalDistance;
    std::vector<edge *> finalPrintout;
    Astar(std::ifstream *map_file, std::ifstream *node_file, int nodeStart, int nodeEnd);
    void astar();
    float heuristic_cost_estimate(vertex *neighbor, vertex *goal);
    edge * sharedEdge(vertex *a, vertex *b);
};


#endif /* Astar_hpp */
