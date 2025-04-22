//
// Created by Meixi Yu on 4/19/25.
//

#include "GraphAdjList.h"
#include "Dijkstra.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // Load graph
    GraphAdjList graph(10000);

    graph.loadGraph("data/data.txt");

    graph.loadLocation("data/data_loc.txt");

//    for (int i=0; i<graph.getNumNodes(); i++){
//        cout << "Node "<< i << " has neighbors: ";
//        for (auto& neighbor: graph.getNeighbors(i)){
//            cout << neighbor.first << "(" << neighbor.second << ") ";
//        }
//        cout << endl;
//    }


    // test Dijkstra
    cout << "___________Test Dijkstra___________" << endl;

    // Start timing
    clock_t start_time_d = clock();

    int total_d= 0;
    vector<int> path_d = dijkstraList(graph, 44, 582, total_d);

    // End timing
    clock_t end_time_d = clock();
    // Calculate time in seconds
    double time_taken_d = double(end_time_d - start_time_d) / CLOCKS_PER_SEC;

    cout << "shortest path from 44 to 582: " << endl;
    for (int node: path_d){
        cout << node << " ";
    }
    cout << endl;
    cout << "Total Distance: " << total_d << endl;
    cout << "Time taken by Dijkstra: " << time_taken_d << " seconds" << endl;


    // test A*
    cout << "___________Test A*___________" << endl;

    // Start timing
    clock_t start_time_a = clock();

    int total_a= 0;
    vector<int> path_a = dijkstraList(graph, 44, 582, total_a);

    // End timing
    clock_t end_time_a = clock();
    // Calculate time in seconds
    double time_taken_a = double(end_time_a - start_time_a) / CLOCKS_PER_SEC;

    cout << "shortest path from 44 to 582 (astar): " << endl;
    for (int node: path_a){
        cout << node << " ";
    }
    cout << endl;
    cout << "Total Distance: " << total_a << endl;
    cout << "Time taken by A star: " << time_taken_a << " seconds" << endl;
    return 0;
}
