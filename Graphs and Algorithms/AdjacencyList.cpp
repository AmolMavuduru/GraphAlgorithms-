//
//  AdjacencyList.cpp
//  Graphs and Algorithms
//
//  Created by Amol on 2/27/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#include <stdio.h>

#include "AdjacencyList.h"
#include "Point.h"

AdjacencyList::AdjacencyList()
{
    numPoints = 0;
}

AdjacencyList::AdjacencyList(std::vector<Point> pointsList)
{
    adjacentPoints.reserve(pointsList.size());
    
    for(int i = 0; i < pointsList.size(); i++)
    {
        adjacentPoints.push_back(pointsList.at(i));
    }
    
    headPoint = adjacentPoints.at(0);
}

AdjacencyList::AdjacencyList(Point p)
{
    adjacentPoints.push_back(p);
    headPoint = p;
}

void AdjacencyList::addPoint(Point p, int weight)
{
    adjacentPoints.push_back(p);
    weights.push_back(weight);
    numPoints++;
}

Point AdjacencyList::head()
{
    return headPoint;
}

int AdjacencyList::size()
{
    return numPoints;
}

void AdjacencyList::clear()
{
    adjacentPoints.clear();
}




