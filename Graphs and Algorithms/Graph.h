//
//  Graph.h
//  Graphs and Algorithms
//
//  Created by Amol on 2/21/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "Point.h"
#include "AdjacencyList.h"
#include <string>
#include <vector>
#include <iostream>

class Graph
{
private:
    std::vector<AdjacencyList> graphList;
    int size;
    
public:
    bool isEmpty()const;
    void clearGraph();
    void print();
    void addPoint(Point p);
    void addAdjacentPoint(Point p, Point adjacent);
    int getSize();
    bool findPoint(Point p);
    
    std::vector<AdjacencyList> getList();
    
    Graph(); //constructor
    Graph(std::vector<AdjacencyList> list);
    ~Graph(); //destructor
    
    
    
};

#endif /* Graph_h */
