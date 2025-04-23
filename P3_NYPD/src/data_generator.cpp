//
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <random>


using namespace std;

//int main(){
//    srand(time(0));
//
//    int numNodes = 10000;
//    int numEdges = 30000;
//
//    ofstream graphFile("../data/data.txt");
//    ofstream locFile("../data/data_loc.txt");
//
//    if (!graphFile.is_open() || !locFile.is_open()){
//        cout << "Unable to open the files" << endl;
//        return 0;
//    }
//    set<pair<int, int>> edges;
//
//    while (edges.size() < numEdges){
//        int u = rand() % numNodes;
//        int v = rand() % numNodes;
//        if (u != v) {
//            if (edges.find({u, v}) == edges.end() && edges.find({v, u}) == edges.end()){
//                edges.insert({u, v});
//            }
//        }
//    }
//    for (auto& e : edges){
//        int weight = 1 + rand() % 20;
//        graphFile << e.first << " " << e.second << " " << weight << endl;
//
//    }
//
//    // Setup (latitude and longitude)
//    std::uniform_real_distribution<double> lat_dist(40.49, 40.92);   // NYC latitude range
//    std::uniform_real_distribution<double> lon_dist(-74.27, -73.68); // NYC longitude range
//    std::mt19937 rng;
//    rng.seed(std::random_device{}());
//
//    // generate 10 random numbers.
//    for (int i = 0; i < numNodes; i++) {
//        double lat = lat_dist(rng);
//        double lon = lon_dist(rng);
//        locFile << i << " " << lat << " " << lon << endl;
//    }
//
//    graphFile.close();
//    locFile.close();
//
//    return 0;
//}