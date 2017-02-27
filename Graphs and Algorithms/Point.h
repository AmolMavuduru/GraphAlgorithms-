//
//  Point.h
//  Graphs and Algorithms
//
//  Created by Amol on 2/21/17.
//  Copyright © 2017 Amol. All rights reserved.
//
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#ifndef Point_h
#define Point_h

class Point
{
private:
    std::string name;
    std::vector<std::string> adjacentPoints; //list of adjacent points
public:
    Point(std::string pName);
    Point();
    std::string pointName();
    std::vector<std::string> adjacent() const; //returns list of all adjacent points
    void addAdjacentPoint(std::string name);
    
    bool operator==(const Point& otherPoint)const;
    
};

#endif /* Point_h */
