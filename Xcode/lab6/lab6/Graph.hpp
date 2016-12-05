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
#include <map>
#include <limits>
#include <iostream>

struct edge;

struct vertex {
    int id;
    float dist;
    float x, y;
    std::vector<edge *> incident_edges;
    vertex(int vertexID) {
        id = vertexID;
        dist = std::numeric_limits<float>::infinity();
    }
    //~vertex() {
        //incident_edges.clear();
    //}
    void insert_edge(edge *e) {
        incident_edges.push_back(e);
    }
    void print() {
        std::cout<< "Vertex #" << id << " " << "NumEdges:" << incident_edges.size() << std::endl;
        std::cout<< "X:" << x << " Y:" << y << std::endl;
    }
};

struct ptr_less {
    bool operator()(vertex *lhs, vertex *rhs) const {
        return lhs->dist < rhs->dist;
    }
};

struct edge {
    int id;
    float distance;
    vertex *incident_vertices[2];
    edge(int edgeID, float dist, vertex *v[2]) {
        id = edgeID;
        distance = dist;
        incident_vertices[0] = v[0];
        incident_vertices[1] = v[1];
    }
    ~edge() {
        delete incident_vertices[0];
        delete incident_vertices[1];
    }
    void print() {
        std::cout<< "Edge #" << id << ": dist=" << distance << "\n" << "Vertex[0]:" << incident_vertices[0] << " Vertex[1]:" << incident_vertices[1] << std::endl;
    }
};

struct Graph {
    std::map<int, vertex*> vertices;
    std::map<int, edge*> edges;
    ~Graph() {
        vertices.clear();
        edges.clear();
    }
    void print() {
        std::cout << "#ofVertices:" << vertices.size() << " #ofEdges:" << edges.size() << std::endl;
    }
};

#endif /* Graph_hpp */
