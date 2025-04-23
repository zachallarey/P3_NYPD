//
// Created by Meixi Yu on 4/19/25.
//

#ifndef P3_ASTAR_H
#define P3_ASTAR_H

#include "GraphAdjList.h"
#include <vector>

using namespace std;

vector<int> astarList(GraphAdjList& graph, int start, int end, int& total_weight);
#endif //P3_ASTAR_H
