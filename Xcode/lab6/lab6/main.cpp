//
//  main.cpp
//  lab6
//
//  Created by Joseph Marshall on 12/4/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#include <iostream>
#include <fstream>

#include <limits>
#include "Dijkstra.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << std::numeric_limits<float>::has_infinity << " " << argc << std::endl;
    
    if (argc == 5 || argc == 6) {
        if (! strcmp(argv[1], "dijkstra")) {
            std::ifstream *mapfile = new std::ifstream(argv[2]);
            if (! mapfile->is_open()) {
                std::cout << "File: " << argv[2] << " could not be opened\n";
                return 0;
            }
            int nodeA, nodeB;
            nodeA = atoi(argv[3]);
            nodeB = atoi(argv[4]);
            Dijkstra(mapfile, nodeA, nodeB);
            return 0;
        }
        else if (strcmp(argv[1], "Astar")) {
            
        }
        else if (strcmp(argv[1], "ID")) {
            
        }
    }
    std::cout << "Usage: ./lab6 dijkstra mymap.cedge nodeID nodeID" << std::endl;
    std::cout << "Usage: ./lab6 Astar mymap.cedge mynodes.cedge nodeID nodeID" << std::endl;
    std::cout << "Usage: ./lab6 ID mymap.cedge mynodes.cedge nodeID nodeID" << std::endl;
    return 0;
}
