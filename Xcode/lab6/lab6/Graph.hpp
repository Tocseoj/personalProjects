//
//  Graph.hpp
//  lab6
//
//  Created by Joseph Marshall on 12/4/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
struct edge;

struct vertex {
    int id;
    std::vector<edge> incident_edges;
};

struct edge {
    int value;
    vertex incident_vertices[2];
};

struct Graph {
    std::vector<vertex> vertices;
    std::vector<edge> edges;
};

#endif /* Graph_hpp */
