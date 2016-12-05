//
//  main.cpp
//  lab6
//
//  Created by Joseph Marshall on 12/4/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Dijkstra.hpp"
#include "Astar.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << std::fixed << std::setprecision(6);
    //std::cout << std::numeric_limits<float>::has_infinity << " " << argc << std::endl;
    
    if (argc == 5 || argc == 6) {
        if (! strcmp(argv[1], "dijkstra")) {
            std::ifstream *mapfile = new std::ifstream(argv[2]);
            if (! mapfile->is_open()) {
                std::cerr << "File: " << argv[2] << " could not be opened\n";
                exit (EXIT_FAILURE);
            }
            int nodeA, nodeB;
            nodeA = atoi(argv[3]);
            nodeB = atoi(argv[4]);
            try {
                Dijkstra d(mapfile, nodeA, nodeB);
                d.dijkstra();
                std::cout << d.finalDistance << "\n";
                for (int i = 0; i < d.finalPrintout.size(); i++) {
                    std::cout << d.finalPrintout.at(i)->id << "\n";
                }
            } catch (std::exception& e) {
                std::cerr << "Invalid input!\n";
                exit(EXIT_FAILURE);
            }
            return 0;
        }
        else if (! strcmp(argv[1], "Astar")) {
            std::ifstream *mapfile = new std::ifstream(argv[2]);
            if (! mapfile->is_open()) {
                std::cerr << "File: " << argv[2] << " could not be opened\n";
                exit (EXIT_FAILURE);
            }
            std::ifstream *nodefile = new std::ifstream(argv[3]);
            if (! nodefile->is_open()) {
                std::cerr << "File: " << argv[2] << " could not be opened\n";
                exit (EXIT_FAILURE);
            }
            int nodeA, nodeB;
            nodeA = atoi(argv[4]);
            nodeB = atoi(argv[5]);
            try {
                Astar a(mapfile, nodefile, nodeA, nodeB);
                a.astar();
                std::cout << a.finalDistance << "\n";
                for (int i = 0; i < a.finalPrintout.size(); i++) {
                    std::cout << a.finalPrintout.at(i)->id << "\n";
                }
            } catch (std::exception& e) {
                std::cerr << "Invalid input!\n";
                exit(EXIT_FAILURE);
            }
            return 0;
        }
        else if (! strcmp(argv[1], "ID")) {
            std::ifstream *mapfile = new std::ifstream(argv[2]);
            if (! mapfile->is_open()) {
                std::cerr << "File: " << argv[2] << " could not be opened\n";
                exit (EXIT_FAILURE);
            }
            std::ifstream *nodefile = new std::ifstream(argv[3]);
            if (! nodefile->is_open()) {
                std::cerr << "File: " << argv[2] << " could not be opened\n";
                exit (EXIT_FAILURE);
            }
            int nodeA, nodeB;
            nodeA = atoi(argv[4]);
            nodeB = atoi(argv[5]);
            try {
                Astar a(mapfile, nodefile, nodeA, nodeB);
                a.astar();
                std::cout << a.finalDistance << "\n";
                for (int i = 0; i < a.finalPrintout.size(); i++) {
                    std::cout << a.finalPrintout.at(i)->id << "\n";
                }
            } catch (std::exception& e) {
                std::cerr << "Invalid input!\n";
                exit(EXIT_FAILURE);
            }
            return 0;
        }
    }
    std::cout << "Usage: ./lab6 dijkstra mymap.cedge nodeID nodeID" << std::endl;
    std::cout << "Usage: ./lab6 Astar mymap.cedge mynodes.cedge nodeID nodeID" << std::endl;
    std::cout << "Usage: ./lab6 ID mymap.cedge mynodes.cedge nodeID nodeID" << std::endl;
    return 0;
}
