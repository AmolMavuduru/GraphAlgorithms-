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
        vertices.push_back(list.at(i).head());
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

int Graph::pointIndex(Point p)
{
    int index = -1;
    bool found = false;
    
    for(int i = 0; i < graphList.size(); i++)
    {
        if(graphList.at(i).head() == p)
        {
            found = true;
            index = i;
        }
    }
    
    return index;
    
}


void Graph::addPoint(Point p)
{
    graphList.push_back(AdjacencyList(p));
    vertices.push_back(p);
    size++;
}

void Graph::addAdjacentPoint(Point p, Point adjacent, int weight)
{
    if(findPoint(p) == false) //If we cannot find p
    {
        AdjacencyList list = AdjacencyList(p);
        list.addPoint(adjacent, weight);
        vertices.push_back(p);
        
       if(findPoint(adjacent))
       {
           graphList.push_back(list);
           size++;
           
           std::cout << "Adjacent point found " << adjacent.pointName() << std::endl;
       }
       else
       {
           graphList.push_back(list);
           size++;
           addPoint(adjacent);
           size++;
           std::cout << " Point " << adjacent.pointName() << " added " << std::endl;
       }
    }
    else
    {
        if(findPoint(adjacent))
        {
            graphList.at(pointIndex(p)).addPoint(adjacent, weight);
        }
        else
        {
          addPoint(adjacent); //Add a new list with the adjacent points
          graphList.at(pointIndex(p)).addPoint(adjacent, weight);
        }
    }
    
    
}

void Graph::setPtWeight(Point p, int weight)
{
    int index = findPoint(p);
    graphList.at(index).head().setWeight(weight);
}

int Graph::getSize()const
{
    return size;
}

const std::vector<AdjacencyList>& Graph::getList()
{
    return graphList;
}

const std::vector<Point>& Graph::vertexList()
{
    return vertices;
}

AdjacencyList Graph::adjacentPoints(Point p)
{
    return graphList.at(pointIndex(p));
}

int Graph::numAdjacentPoints(Point p)
{
    return graphList.at(pointIndex(p)).size();

}

void Graph::print()
{
    for(int i = 0; i < graphList.size(); i++)
    {
        graphList.at(i).printList();
    }
}



