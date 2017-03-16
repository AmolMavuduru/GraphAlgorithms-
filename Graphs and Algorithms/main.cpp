//
//  main.cpp
//  Graphs and Algorithms
//
//  Created by Amol on 2/21/17.
//  Copyright © 2017 Amol. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Point.h"
#include "Graph.h"
#include "AdjacencyList.h"

//Dijkstra's Algorithm implemented as a function

void Dijkstra(Graph graph, Point start, Point end)
{
    std::vector<Point> sptSet;
    sptSet.reserve(graph.getSize());
    
    if(graph.findPoint(start) && graph.findPoint(end)) //If both start and end point are in the graph
    {
        
        for(int i = 0; i < graph.getSize(); i++)
        {
            if(graph.vertexList().at(i) != start)
            {
              graph.setPtWeight(graph.vertexList().at(i), INT_MAX); //Sets the weight of each point to the max value.
            }
            else
            {
              graph.setPtWeight(graph.vertexList().at(i), 0);
            }
        }
        
        sptSet.push_back(start);
        Point u = start;
        
        while(sptSet.size() < graph.getSize())
        {
            int index = graph.pointIndex(u);
            
            for(int i = 1; i < graph.numAdjacentPoints(u); i++)
            {
                
            }
        }
        
    }
    else
    {
        std::cout << "Points " << start.pointName() << " or " << end.pointName() << " are not in the graph!" << std::endl;
    }
}


int main() {
    
  Point p = Point("A");
  AdjacencyList list = AdjacencyList(p);
  std::vector<AdjacencyList> graphList;
  graphList.push_back(list);
  
  Graph g = Graph(graphList);
  g.addAdjacentPoint(p, Point("B"), 3);
  g.addAdjacentPoint(p, Point("C"), 4);
  g.addAdjacentPoint(Point("B"), p, 2);
    
  g.print();

    
    return 0;
}
