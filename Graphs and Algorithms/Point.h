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
    int ptWeight;
    
public:
    Point(std::string pName);
    Point(std::string pName, int weight);
    Point();
    std::string pointName();
    int weight();
    void setWeight(int newWeight);
    
    bool operator==(const Point& otherPoint)const;
    bool operator!=(const Point& otherPoint)const;
    
};

#endif /* Point_h */
