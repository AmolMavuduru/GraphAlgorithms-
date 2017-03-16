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
    weights.push_back(0);
}

AdjacencyList::AdjacencyList(std::vector<Point> pointsList)
{
    adjacentPoints.reserve(pointsList.size());
    
    for(int i = 0; i < pointsList.size(); i++)
    {
        adjacentPoints.push_back(pointsList.at(i));
    }
    
    headPoint = adjacentPoints.at(0);
    
    numPoints = pointsList.size();
}

bool AdjacencyList::empty()
{
    return (numPoints == 0);
}

AdjacencyList::AdjacencyList(Point p)
{
   adjacentPoints.reserve(10);
   adjacentPoints.push_back(p);
    headPoint = p;
    weights.push_back(0);
}

void AdjacencyList::addPoint(Point p, int weight)
{
    adjacentPoints.reserve(adjacentPoints.size() + 1);
    adjacentPoints.push_back(p);
    weights.reserve(weights.size() + 1);
    weights.push_back(weight);
    numPoints++;
}

Point& AdjacencyList::head()
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

void AdjacencyList::printList()
{
    if(empty())
    {
        std::cout << "List is empty";
    }
    else
    {
        std::cout << headPoint.pointName() << " (head point) ";
        
        for(int i = 1; i < adjacentPoints.size(); i++)
        {
            std::cout << " --  Weight: "<< weights.at(i) << " -- " << adjacentPoints.at(i).pointName();
        }
        
        std::cout << std::endl;
    }
}




