//
// Created by Meixi Yu on 4/19/25.
//

#ifndef P3_DIJKSTRA_H
#define P3_DIJKSTRA_H

#include "GraphAdjList.h"
#include <vector>

vector<int> dijkstraList(GraphAdjList& graph, int start, int end, int& total_weight);
// vector<int> dijkstraMatrix(GraphAdjMatrix& graph, int start, int end, int& totalDistance);
#endif //P3_DIJKSTRA_H
