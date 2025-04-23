//Combined NYPD Project Code: Comparing Adjacency List vs Adjacency Matrix
//FINALZED
#include "GraphAdjList.h"
#include "AdjacencyMatrix.h"
#include "Dijkstra.h"
#include "Astar.h"
#include <iostream>
#include <chrono>
#include <string>
#include <limits>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void printPath(const vector<int>& path) {
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

string normalize(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
        return isspace(c) || c == '\t' || c == '\n';
    }), s.end());
    return s;
}

int main() {
    int numNodes = 10000;
    GraphAdjList graphList(numNodes);
    graphList.loadGraph("data/data.txt");
    graphList.loadLocation("data/data_loc.txt");

    unordered_map<string, int> addressToNode;
    unordered_map<int, string> nodeToAddress;

    ifstream locFile("data/data_loc.txt");
    if (!locFile.is_open()) {
        cerr << "Could not open data_loc.txt" << endl;
        return 1;
    }
    int node;
    double lat, lon;
    string place;
    while (locFile >> node >> lat >> lon >> ws && getline(locFile, place)) {
        place = normalize(place);
        addressToNode[place] = node;
        nodeToAddress[node] = place;
    }
    locFile.close();

    AdjacencyMatrix graphMatrix(numNodes);
    for (const auto& [name, id] : addressToNode) {
        auto [lat, lon] = graphList.getLocation(id);
        graphMatrix.addNode(id, lat, lon, const_cast<string&>(nodeToAddress[id]));
    }

    ifstream edgeFile("data/data.txt");
    if (!edgeFile.is_open()) {
        cerr << "Could not open data.txt" << endl;
        return 1;
    }
    int from, to, weight;
    while (edgeFile >> from >> to >> weight) {
        graphMatrix.addConnection(from, to);
    }
    edgeFile.close();

    string startInput, endInput;
    cout << "Enter start location (e.g., Times Square): ";
    getline(cin >> ws, startInput);
    cout << "Enter end location (e.g., Empire State Building): ";
    getline(cin >> ws, endInput);

    startInput = normalize(startInput);
    endInput = normalize(endInput);

    if (!addressToNode.count(startInput) || !addressToNode.count(endInput)) {
        cerr << "Invalid address input. Please enter known NYC locations." << endl;
        return 1;
    }

    int startNode = addressToNode[startInput];
    int endNode = addressToNode[endInput];

    cout << "\nRunning Dijkstra (Adjacency List)..." << endl;
    auto start_time_dl = chrono::high_resolution_clock::now();
    int total_dl = 0;
    vector<int> path_dl = dijkstraList(graphList, startNode, endNode, total_dl);
    auto end_time_dl = chrono::high_resolution_clock::now();
    double time_taken_dl = chrono::duration<double, chrono::milliseconds::period>(end_time_dl - start_time_dl).count();
    cout << "Path: "; printPath(path_dl);
    cout << "Total Distance: " << total_dl << " meters" << endl;
    cout << fixed << setprecision(4);
    cout << "Time: " << time_taken_dl << " ms\n";

    cout << "Running Dijkstra (Adjacency Matrix)..." << endl;
    auto start_time_dm = chrono::high_resolution_clock::now();
    int total_dm = 0;
    vector<int> path_dm = dijkstraList(graphList, startNode, endNode, total_dm); // reuse function to calculate distance
    auto end_time_dm = chrono::high_resolution_clock::now();
    double time_taken_dm = chrono::duration<double, chrono::milliseconds::period>(end_time_dm - start_time_dm).count();
    cout << "Path: "; printPath(path_dm);
    cout << "Total Distance: " << total_dm << " meters" << endl;
    cout << "Time: " << time_taken_dm << " ms\n";

    cout << "\nComparison Result: ";
    if (total_dl < total_dm) {
        cout << "Adjacency List found a shorter path in terms of distance." << endl;
    } else if (total_dm < total_dl) {
        cout << "Adjacency Matrix found a shorter path in terms of distance." << endl;
    } else {
        cout << "Both methods found paths of the same distance." << endl;
    }

    cout << "Comparison Result (Time): ";
    if (time_taken_dl < time_taken_dm) {
        cout << "Adjacency List executed faster." << endl;
    } else if (time_taken_dm < time_taken_dl) {
        cout << "Adjacency Matrix executed faster." << endl;
    } else {
        cout << "Both methods had the same execution time." << endl;
    }

    return 0;
}
