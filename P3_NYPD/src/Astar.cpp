//
//
#include "Astar.h"
#include <queue>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

double h(GraphAdjList& graph, int node1, int node2){
    auto [lat1, lon1] = graph.getLocation(node1);
    auto [lat2, lon2] = graph.getLocation(node2);
    double estimate = sqrt((lat1-lat2)*((lat1-lat2)) + (lon1-lon2)*(lon1-lon2));

    return estimate;
}

vector<int> astarList(GraphAdjList& graph, int start, int end, int& total_weight){
    int n = graph.getNumNodes();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[start] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({h(graph, start, end), start});

    while (!pq.empty()){
        double curr_priority = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_node == end)
            break;

        for (auto neighbor :  graph.getNeighbors(curr_node)){
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[curr_node] + weight < dist[nextNode]){
                dist[nextNode] = dist[curr_node] + weight;
                prev[nextNode] = prev[curr_node];
                double nPriority = dist[nextNode] + h(graph, nextNode, end);
                pq.push({nPriority, nextNode});

            }
        }
    }

    vector<int> path;
    for (int i=end; i!= -1; i=prev[i]){
        path.push_back(i);
    }
    std::reverse(path.begin(), path.end());
    total_weight = dist[end];
    return path;
}
