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

int main() {
    
  Point p = Point("A");
  AdjacencyList list = AdjacencyList(p);
  std::vector<AdjacencyList> graphList;
  graphList.push_back(list);
  
  Graph g = Graph(graphList);
  g.addAdjacentPoint(p, Point("B"), 3);
  g.addAdjacentPoint(p, Point("C"), 4);
  g.addAdjacentPoint(Point("B"), p, 2);


    
    return 0;
}
