//
//  AdjacencyList.h
//  Graphs and Algorithms
//
//  Created by Amol on 2/27/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#ifndef AdjacencyList_h
#define AdjacencyList_h

#include "Point.h"

class AdjacencyList
{
private:
    std::vector<Point> adjacentPoints;
    std::vector<int> weights;
    Point headPoint;
    int numPoints;
public:
    void addPoint(Point p, int weight);
    bool empty();
    AdjacencyList();
    AdjacencyList(std::vector<Point> pointsList);
    AdjacencyList(Point p);
    Point& head();
    int size();
    void clear();
    void printList();
    
};



#endif /* AdjacencyList_h */
