# New York Pedestrian Directory (NYPD)

## Description
The New York Pedestrian Directory (NYPD) is a C++ application that simulates pedestrian navigation across New York City using real-world landmark data.  
It compares the performance and output of Dijkstra's Algorithm using two different graph structures:  
- **Adjacency List**  
- **Adjacency Matrix**  

Each structure is evaluated for how efficiently it computes the shortest path (in meters) and runtime (in milliseconds) between two known NYC locations.

## Key Features
- Accepts **real NYC location names** like `Times Square`, `Empire State Building`, and `Central Park`
- Routes are generated from **geographic coordinates** using the Haversine formula
- Distance reflects **realistic walking paths** via nodes connected within 1.5km proximity
- Compares performance of adjacency list and matrix versions of Dijkstra
- Handles cases where no path exists

## Programming Language Used
- C++

## File Structure
- `/src` contains source code for:
  - `GraphAdjList` and `GraphAdjMatrix`
  - `Dijkstra` and `A*` algorithmsa
- `/data` contains graph data:
  - `data.txt` — edges with weights based on real geographic walking distances
  - `data_loc.txt` — node IDs mapped to real-world lat/lon and NYC place names

## Data Source & Accuracy
- `data_loc.txt` contains over 100 real NYC places with approximate latitude/longitude
- `data.txt` was generated using Haversine distance between locations **within a 1.5km (1 mile) walking radius**
- This mae it so that only geographically WALKABLE paths are considered
- Total distances returned are **in meters** and represent real-world route approximations

## How to Run
- Open `main.cpp` in CLion or another C++ IDE
- Build and run the project
- When prompted, type a **start and end location** (e.g., `Times Square`, `Central Park`)
- Output will show:
  - The computed path
  - Total distance in meters
  - Runtime in milliseconds
  - A comparison of distance and speed between both graph structures

## Authors
- Anirudh Mukund  
- Zachary Miguel Allarey  
- Macy Yu
