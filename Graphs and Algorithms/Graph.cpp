//
//  Graph.cpp
//  Graphs and Algorithms
//
//  Created by Amol on 2/27/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#include <stdio.h>

#include "Graph.h"
#include "Point.h"
#include "AdjacencyList.h"
#include "vector"

Graph::Graph()
{
    size = 0;
}

bool Graph::isEmpty() const
{
    return (graphList.size() == 0);
}

Graph::Graph(std::vector<AdjacencyList> list)
{
    for(int i = 0; i < list.size(); i++)
    {
        graphList.push_back(list.at(i));
    }
    
    size = list.size();
}

void Graph::clearGraph()
{
    for(int i = 0; i < graphList.size(); i++)
    {
        graphList.at(i).clear();
    }
}

bool Graph::findPoint(Point p)
{
    bool found = false;
    
    for(int i = 0; i < graphList.size(); i++)
    {
        if(graphList.at(i).head() == p)
        {
            return true;
        }
    }
    
    return found;
}

void Graph::addPoint(Point p)
{
    graphList.push_back(AdjacencyList(p));
    size++;
}

void Graph::addAdjacentPoint(Point p, Point adjacent, int weight)
{
    if(findPoint(p) == false)
    {
        AdjacencyList list = AdjacencyList(p);
        list.addPoint(adjacent, weight);
        
       if(findPoint(adjacent))
       {
           graphList.push_back(list);
           size++;
       }
       else
       {
           graphList.push_back(list);
           size++;
           addPoint(adjacent);
           size++;
       }
    }
    
}

int Graph::getSize()const
{
    return size;
}



