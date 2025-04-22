#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <limits>
#include <string>

class AdjacencyMatrix{
public:
    AdjacencyMatrix(int n) : sizeOfMatrix(n), tensor(n, std::vector<double>(n, std::numeric_limits<double>::infinity())) {}
    void addNode(int key, double latitude, double longitude, std::string& address);
    void addConnection(int from, int to);
    std::vector<int> dijkstraAlgorithm(int startingPoint, int endingPoint);
    void printShortestPossiblePath(std::vector<int>& mostEfficientPath);
    void discoverPath(std::string& startingPoint, std::string& endingPoint);

private:
    int sizeOfMatrix;
    std::vector<std::vector<double>> tensor;
    std::unordered_map<int, std::pair<double, double>> keyToLatitudeAndLongitude;
    std::unordered_map<std::string, int> addressToKey;
    std::unordered_map<int, std::string> keyToAddress;
    double distanceCalculator(double latitude1, double longitude1, double latitude2, double longitude2);
};



