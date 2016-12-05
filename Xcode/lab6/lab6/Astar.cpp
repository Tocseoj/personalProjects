//
//  Astar.cpp
//  lab6
//
//  Created by Joseph Marshall on 12/5/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#include "Astar.hpp"

Astar::Astar(std::ifstream *map_file, std::ifstream *node_file, int nodeStart, int nodeEnd) {
    start = nodeStart;
    end = nodeEnd;
    int edgeID, nodeID1, nodeID2;
    float dist;
    int EOFTest;
    while (*map_file >> EOFTest, !map_file->eof()) {
        edgeID = EOFTest;
        *map_file >> nodeID1 >> nodeID2 >> dist;
        if (map_file->fail()) {
            std::cerr << "Invalid Input!\n";
            exit(EXIT_FAILURE);
        }
        vertex *A;
        vertex *B;
        try {
            A = graph.vertices.at(nodeID1);
        } catch (std::exception& e) {
            A = new vertex(nodeID1);
        }
        try {
            B = graph.vertices.at(nodeID2);
        } catch (std::exception& e) {
            B = new vertex(nodeID2);
        }
        vertex *v[] = {A, B};
        edge *e = new edge(edgeID, dist, v);
        A->insert_edge(e);
        B->insert_edge(e);
        graph.edges[edgeID] = e;
        graph.vertices[nodeID1] = A;
        graph.vertices[nodeID2] = B;
    }
    map_file->close();
    delete map_file;
    
    int nodeID;
    float xcoord, ycoord;
    while (*node_file >> EOFTest, !node_file->eof()) {
        nodeID = EOFTest;
        *node_file >> xcoord >> ycoord;
        if (node_file->fail()) {
            std::cerr << "Invalid map file input!\n";
            exit(EXIT_FAILURE);
        }
        try {
            vertex *v = graph.vertices.at(nodeID);
            v->x = xcoord;
            v->y = ycoord;
        } catch (std::exception& e) {
            std::cerr << "Invalid node file input!";
            exit(EXIT_FAILURE);
        }
    }
    node_file->close();
    delete node_file;
}

void Astar::astar() {
    vertex *v = graph.vertices.at(start);
    vertex *goal = graph.vertices.at(end);
    v->dist = 0;
    openSet.insert(v);
    gScore[v] = 0;
    fScore[v] = heuristic_cost_estimate(v, goal);
    for(auto const& ent : graph.vertices) {
        if (ent.first != start) {
            gScore[ent.second] = std::numeric_limits<float>::infinity();
            fScore[ent.second] = std::numeric_limits<float>::infinity();
        }
    }
    bool found = false;
    while (! openSet.empty()) {
        vertex *v = *openSet.begin();
        if (v->id == end) {
            found = true;
            break;
        }
        openSet.erase(v);
        closedSet.insert(v);
        for (int i = 0; i < v->incident_edges.size(); i++) {
            vertex *other;
            if (v->incident_edges.at(i)->incident_vertices[0]->id == v->id) {
                other = v->incident_edges.at(i)->incident_vertices[1];
            } else {
                other = v->incident_edges.at(i)->incident_vertices[0];
            }
            if (closedSet.count(other)) {
                continue;
            }
            float tentative_gScore = gScore[v] + v->incident_edges.at(i)->distance;
            if (! openSet.count(other)) {
                openSet.insert(other);
            }
            else if (tentative_gScore >= gScore[other]) {
                continue;
            }
            cameFrom[other->id] = v;
            gScore[other] = tentative_gScore;
            float fdist = gScore[other] + heuristic_cost_estimate(other, goal);
            other->dist = fdist;
            fScore[other] = fdist;
        }
    }
    if (found) {
        finalDistance = fScore[goal];
        vertex *u = cameFrom[end];
        while (u != nullptr) {
            shortestPath.push_back(u);
            u = cameFrom[u->id];
        }
        vertex *a = graph.vertices.at(start);
        vertex *b;
        shortestPath.pop_back();
        while (shortestPath.size() > 0) {
            b = shortestPath.back();
            shortestPath.pop_back();
            edge * e = sharedEdge(a, b);
            finalPrintout.push_back(e);
            a = b;
        }
        b = graph.vertices.at(end);
        edge * e = sharedEdge(a, b);
        finalPrintout.push_back(e);
    }
    if (! found) {
        std::cout << "Inf" << "\n";
        exit(0);
    }
}

float Astar::heuristic_cost_estimate(vertex *neighbor, vertex *goal) {
    float dx = std::abs(neighbor->x - goal->x);
    float dy = std::abs(neighbor->y - goal->y);
    float D = 0, D2 = 1;
    return D2 = (1 * (dx + dy) + (D2 - 2 * 1) * 0 * std::min(dx, dy)), D;
}

edge * Astar::sharedEdge(vertex *a, vertex *b) {
    for (int i = 0; i < a->incident_edges.size(); i++) {
        for (int j = 0; j < b->incident_edges.size(); j++) {
            if (a->incident_edges.at(i) == b->incident_edges.at(j)) {
                return a->incident_edges.at(i);
            }
        }
    }
    return nullptr;
}
