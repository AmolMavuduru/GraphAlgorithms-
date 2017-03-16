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
    ptWeight = 0;
    
}

Point::Point(std::string pName, int weight)
{
    name = pName;
    ptWeight = weight;
}

Point::Point()
{
    name = "";
    ptWeight = 0;
}

std::string Point::pointName()
{
    return name;
}

int Point::weight()
{
    return ptWeight;
}

void Point::setWeight(int newWeight)
{
    ptWeight = newWeight;
}

bool Point::operator==(const Point& otherPoint)const
{
    return (name == otherPoint.name);
}

bool Point::operator!=(const Point& otherPoint)const
{
    return (name != otherPoint.name);
}


