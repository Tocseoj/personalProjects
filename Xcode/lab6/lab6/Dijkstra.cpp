//
//  Dijkstra.cpp
//  lab6
//
//  Created by Joseph Marshall on 12/4/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#include "Dijkstra.hpp"

Dijkstra::Dijkstra(std::ifstream *map_file, int nodeStart, int nodeEnd) {
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
            toDelete.push_back(A);
        }
        try {
            B = graph.vertices.at(nodeID2);
        } catch (std::exception& e) {
            B = new vertex(nodeID2);
            toDelete.push_back(B);
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
}

Dijkstra::~Dijkstra() {
    for(auto const& ent : graph.edges) {
        edge *temp = ent.second;
        delete temp;
    }
    for(auto const& ent : toDelete) {
        vertex *temp = ent;
        delete temp;
    }
}

void Dijkstra::dijkstra() {
    dist[start] = 0;
    prev[start] = nullptr;
    try {
        graph.vertices.at(start)->dist = 0;
    } catch (std::exception& e) {
        std::cerr << "Invalid start vertex\n";
        exit(EXIT_FAILURE);
    }
    for(auto const& ent : graph.vertices) {
        if (ent.first != start) {
            dist[ent.first] = std::numeric_limits<float>::infinity();
            try {
                graph.vertices.at(ent.first)->dist = std::numeric_limits<float>::infinity();
            } catch (std::exception& e) {
                std::cerr << "Invalid vertex\n";
                exit(EXIT_FAILURE);
            }
            prev[ent.first] = nullptr;
        }
        min_heap[ent.second] = dist[ent.first];
    }
    bool found = false;
    while (! min_heap.empty()) {
        vertex *entry = min_heap.begin()->first;
        float distance = min_heap.begin()->second;
        min_heap.erase(entry);
        if (entry->id == end) {
            found = true;
            break;
        }
        for (int i = 0; i < entry->incident_edges.size(); i++) {
            vertex *other;
            if (entry->incident_edges.at(i)->incident_vertices[0]->id == entry->id) {
                other = entry->incident_edges.at(i)->incident_vertices[1];
            } else {
                other = entry->incident_edges.at(i)->incident_vertices[0];
            }
            float alt = distance + entry->incident_edges.at(i)->distance;
            if (alt < dist[other->id]) {
                dist[other->id] = alt;
                prev[other->id] = entry;
                min_heap.erase(other);
                other->dist = alt;
                min_heap[other] = alt;
            }
        }
    }
    if (found) {
        finalDistance = dist.at(end);
        vertex *u = prev.at(end);
        while (u != nullptr) {
            shortestPath.push_back(u);
            u = prev.at(u->id);
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

void Dijkstra::print() {
    std::cout << "Dist[]\n";
    for (int i = 0; i < dist.size(); i++) {
        std::cout << i << ":" << dist.at(i) << " ";
    }
    std::cout << "\nPrev[]\n";
    for (int i = 0; i < prev.size(); i++) {
        std::cout << i << ":" << prev.at(i) << " ";
    }
    std::cout << "\nShortestPath\n";
    for (int i = 0; i < finalPrintout.size(); i++) {
        std::cout << i << ":" << finalPrintout.at(i)->id << " ";
    }
    std::cout << std::endl;
}

edge * Dijkstra::sharedEdge(vertex *a, vertex *b) {
    for (int i = 0; i < a->incident_edges.size(); i++) {
        for (int j = 0; j < b->incident_edges.size(); j++) {
            if (a->incident_edges.at(i) == b->incident_edges.at(j)) {
                return a->incident_edges.at(i);
            }
        }
    }
    return nullptr;
}
