//
// Created by animu on 4/21/2025.
//
#include "AdjacencyMatrix.h"


void AdjacencyMatrix::addNode(int key, double latitude, double longitude, std::string &address) {

    keyToLatitudeAndLongitude[key] = {latitude, longitude};
    addressToKey[address] = key;
    keyToAddress[key] = address;

}

// Uses the Haversine Formula to calculate distance between two specified spherical coordinates. Implementation was taken from wikipeida.
double AdjacencyMatrix::distanceCalculator(double latitude1, double longitude1, double latitude2, double longitude2) {
    const double R = 6371000; // Earth radius in meters
    double dLat = (latitude2 - latitude1) * M_PI / 180.0;
    double dLon = (longitude2 - longitude1) * M_PI / 180.0;
    latitude1 *= M_PI / 180.0;
    latitude2 *= M_PI / 180.0;

    double a = sin(dLat/2) * sin(dLat/2) +
               sin(dLon/2) * sin(dLon/2) * cos(latitude1) * cos(latitude2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}


void AdjacencyMatrix::addConnection(int from, int to) {

    if (from >= sizeOfMatrix || to >= sizeOfMatrix) {
        std::cerr << "Invalid key.\n";
        return;
    }

    if (!keyToLatitudeAndLongitude.count(from) || !keyToLatitudeAndLongitude.count(to)) {
        std::cerr << "A key specified was not found.\n";
        return;
    }

    auto [latitude1, longitude1] = keyToLatitudeAndLongitude[from];
    auto [latitude2, longitude2] = keyToLatitudeAndLongitude[to];
    double distanceBetweenPoints = distanceCalculator(latitude1,longitude1, latitude2, longitude2);
    tensor[from][to] = distanceBetweenPoints;
    tensor[to][from] = distanceBetweenPoints;

}

std::vector<int> AdjacencyMatrix::dijkstraAlgorithm(int startingPoint, int endingPoint) {
    std::vector<double> distances(sizeOfMatrix, std::numeric_limits<double>::infinity());
    std::vector<int> previous(sizeOfMatrix, -1);
    distances[startingPoint] = 0;

    using Point = std::pair<double, int>;
    std::priority_queue<Point, std::vector<Point>, std::greater<Point>> priorityQueue;
    priorityQueue.emplace(0.0, startingPoint);

    while (priorityQueue.empty() != true) {
        auto[instantDistance, instantNode] = priorityQueue.top();
        priorityQueue.pop();
        if (instantNode == endingPoint) {
            break;
        }
        else {
            for (int x = 0; x < sizeOfMatrix; x++) {
                if (tensor[instantNode][x] != std::numeric_limits<double>::infinity()) {
                    double alternate = instantDistance + tensor[instantNode][x];
                    if (alternate < distances[x]) {
                        distances[x] = alternate;
                        previous[x] = instantNode;
                        priorityQueue.emplace(alternate, x);
                    }
                }
            }
        }
    }

    std::vector<int> shortestPossiblePath;
    for (int x = endingPoint; x!= -1; x = previous[x]) {
        shortestPossiblePath.push_back(x);
    }
    std::reverse(shortestPossiblePath.begin(), shortestPossiblePath.end());
    return shortestPossiblePath;
}

void AdjacencyMatrix::printShortestPossiblePath(std::vector<int> &mostEfficientPath) {
    std::cout << "The shortest possible path is: \n";
    double totalDistanceTravelled = 0.0;
    for (size_t x = 0; x < mostEfficientPath.size(); x++) {
        std::cout << x + 1 << ": " << keyToAddress[mostEfficientPath[x]] << "\n";
        if (x + 1 < mostEfficientPath.size()) {
            totalDistanceTravelled = totalDistanceTravelled + tensor[mostEfficientPath[x]][mostEfficientPath[x+1]];
        }
    }

    std::cout << "The total distance travelled is: " << (totalDistanceTravelled * 0.000621371) << "miles\n";
}

void AdjacencyMatrix::discoverPath(std::string &startingPoint, std::string &endingPoint) {
    if (!addressToKey.count(startingPoint) || !addressToKey.count(endingPoint)) {
        std::cerr << "An address specified was not found.\n";
        return;
    }
    int start = addressToKey[startingPoint];
    int end = addressToKey[endingPoint];
    std::vector<int> discoveredPath = dijkstraAlgorithm(start, end);
    printShortestPossiblePath(discoveredPath);
}


