//
//  Point.cpp
//  Graphs and Algorithms
//
//  Created by Amol on 2/21/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "Point.h"


Point::Point(std::string pName)
{
    name = pName;
}

Point::Point()
{
    name = "";
}

std::string Point::pointName()
{
    return name;
}

std::vector<std::string> Point::adjacent() const
{
    return adjacentPoints;
}

void Point::addAdjacentPoint(std::string name)
{
    adjacentPoints.push_back(name);
}

bool Point::operator==(const Point& otherPoint)const
{
    return (name == otherPoint.name);
}

