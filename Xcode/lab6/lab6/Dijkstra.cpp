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
    std::string token;
    while (!map_file->eof()) {
        *map_file >> edgeID >> nodeID1 >> nodeID2 >> dist;
        std::cout << edgeID << " " << nodeID1 << " " << nodeID2 << " " << dist << "\n";
    }
    map_file->close();
    delete map_file;
}

Dijkstra::~Dijkstra() {
    
}

void Dijkstra::dijkstra() {
    
}
