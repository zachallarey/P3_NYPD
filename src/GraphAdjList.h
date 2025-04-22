//
// Created by Meixi Yu.
//

#ifndef P3_GRAPHADJLIST_H
#define P3_GRAPHADJLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility> // for pair<>
using namespace std;

class GraphAdjList{
public:
    //constructor with number of vertex
    GraphAdjList(int numNodes);
    // add connection and node's location
    void addEdge(int from, int to, int weight);
    void addLocation(int node, double latitude, double longitude);
    // read all the edges/all node locations from a text file
    void loadGraph(const string& filename);
    void loadLocation(const string& filename);
    // get neighbor list of pairs of (neighbor node, weight) for a node
    vector<pair<int, int>>& getNeighbors(int node);
    pair<double, double> getLocation(int node);

    int getNumNodes();

private:
    int numNodes;
    vector<vector<pair<int, int>>> adjList;
    unordered_map<int, pair<double, double>> locations;
};

#endif //P3_GRAPHADJLIST_H
