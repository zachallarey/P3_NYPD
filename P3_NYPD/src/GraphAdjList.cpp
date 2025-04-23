//
// Created by Meixi Yu on 4/19/25.
//
#include "GraphAdjList.h"

GraphAdjList::GraphAdjList(int numNodes) {
    this->numNodes = numNodes;
    adjList.resize(numNodes); // Prepare a neighbor list for every node
}
// Save the edge from one to another
void GraphAdjList::addEdge(int from, int to, int weight) {
    adjList[from].push_back({to, weight});
    adjList[to].push_back({from, weight});

}
// save latitude and longitude
void GraphAdjList::addLocation(int node, double latitude, double longitude) {
    locations[node] = {latitude, longitude};
}

// Read and save all connections
void GraphAdjList::loadGraph(const std::string &filename) {
    ifstream infile(filename);
    if (!infile.is_open()){
        cout << "Unable to open the file- " << filename << endl;
        return;
    }
    int from, to, weight;
    while (infile >> from >> to >> weight){
        addEdge(from, to, weight);
    }

    infile.close();
}


void GraphAdjList::loadLocation(const std::string &filename) {
    ifstream  infile(filename);
    if (!infile.is_open()){
        cout << "Unable to open the file- " << filename << endl;
        return;
    }
    int node;
    double lat, lon;
    while (infile >> node >> lat >> lon){
        addLocation(node, lat, lon);
    }
    infile.close();
}
// Return vector of pairs of (neighbor, weight)
vector<pair<int, int>>& GraphAdjList::getNeighbors(int node) {
    return adjList[node];
}

// return latitude, longitude
pair<double, double> GraphAdjList::getLocation(int node) {
    auto it = locations.find(node);
    if (it!= locations.end()){
        return it->second;
    } else {
        return {-1.0, -1.0};
    }
}

// return total num of nodes
int GraphAdjList::getNumNodes() {
    return numNodes;
}

bool GraphAdjList::hasLocation(int nodeID) {
    return locations.count(nodeID) > 0;
}
//FINALZED