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

//This class contains the implementation of a weighted graph

class Graph
{
private:
    std::vector<AdjacencyList> graphList; //This list is basically an adjacency list or a list of lists of adjacent points
    std::vector<Point> vertices;
    int size;
    
public:
    bool isEmpty()const;
    void clearGraph();
    void print();
    void addPoint(Point p);
    void addAdjacentPoint(Point p, Point adjacent, int weight);
    int getSize()const;
    bool findPoint(Point p);
    int pointIndex(Point p);
    void setPtWeight(Point p, int weight);
    AdjacencyList adjacentPoints(Point p);
    int numAdjacentPoints(Point p);
    
    const std::vector<AdjacencyList>& getList();
    const std::vector<Point>& vertexList();
    
    Graph(); //constructor
    Graph(std::vector<AdjacencyList> list);
    
    
    
};

#endif /* Graph_h */
