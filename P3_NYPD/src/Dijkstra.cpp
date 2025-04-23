//
// Created by Meixi Yu on 4/19/25.
//
#include "Dijkstra.h"
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <climits>
//FINALZED

using namespace std;

vector<int> dijkstraList(GraphAdjList& graph, int start,
                         int end, int& total_weight){
    int n=graph.getNumNodes();
    vector<int> dist(n,INT_MAX);
    vector<int> prev(n, -1); // default path to be changed
    dist[start] = 0;
    // set up a minHeap to choose the closet node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // push the start node on the minHeap
    pq.push({0, start});

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        // stop if reach the destination node
        if (curr_node == end)
            break;
        // explore all the neighbors
        for (auto neighbor : graph.getNeighbors(curr_node)){
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            // relaxation
            if (dist[curr_node] + weight < dist[nextNode]){
                dist[nextNode] = dist[curr_node] + weight;
                prev[nextNode] = curr_node;
                pq.push({dist[nextNode], nextNode});
            }

        }
    }
    // reconsttruct the path
    vector<int> path;
    for (int i = end; i != -1; i = prev[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());

    total_weight = dist[end];
    return path;

}