#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    double lon;
    double lat;
};

vector<Node> nodes;
vector<vector<pair<int, double>>> adjList;

// Parse coordinates from string like "POINT (-73.79174966999994 40.72578303100005)"
Node parseCoordinates(const string& coordStr, int id) {
    double lon, lat;
    sscanf(coordStr.c_str(), "POINT (%lf %lf)", &lon, &lat);
    return {id, lon, lat};
}

// Use haversine formula for accurate geographic distance based on lat/lon
const double EARTH_RADIUS_KM = 6371.0;
double haversineDist(const Node& a, const Node& b) {
    double dLat = (b.lat - a.lat) * M_PI / 180.0;
    double dLon = (b.lon - a.lon) * M_PI / 180.0;

    double lat1 = a.lat * M_PI / 180.0;
    double lat2 = b.lat * M_PI / 180.0;

    double aCalc = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * atan2(sqrt(aCalc), sqrt(1 - aCalc));
    return EARTH_RADIUS_KM * c;
}

// Build adjacency list by connecting each node to its k nearest neighbors
void buildAdjList(int k = 3) {
    adjList.resize(nodes.size());
    for (int i = 0; i < nodes.size(); i++) {
        vector<pair<double, int>> dists;
        for (int j = 0; j < nodes.size(); j++) {
            if (i != j) {
                dists.emplace_back(haversineDist(nodes[i], nodes[j]), j);
            }
        }
        sort(dists.begin(), dists.end());
        for (int x = 0; x < min(k, (int)dists.size()); x++) {
            adjList[i].emplace_back(dists[x].second, dists[x].first);
        }
    }
}

// Load nodes from CSV file
void importCSV(const string& filename) {
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    int id = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string coord;
        getline(ss, coord, ',');
        Node node = parseCoordinates(coord, id++);
        nodes.push_back(node);
    }
}

int main() {
    importCSV("NYC_Honorary_Street_Names_Map__Intersection_.csv");
    cout << "Imported " << nodes.size() << " nodes.\n";

    auto start = chrono::high_resolution_clock::now();
    buildAdjList();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Adjacency List built in: " << duration.count() << " seconds\n";

    // Print a sample of the adjacency list
    cout << "\nSample connections from node 0:\n";
    for (auto& neighbor : adjList[0]) {
        cout << " -> Node " << neighbor.first << " (Distance: " << neighbor.second << " km)\n";
    }

    return 0;
}
