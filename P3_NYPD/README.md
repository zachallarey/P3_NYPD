# New York Pedestrian Directory (NYPD)

## Description
In this project, we compared the 
performance of Dijkstra's Algorithm and A* Search Algorithm using two different data structures: 
adjacency list and adjacency matrix.  
The goal of this project is to see how different algorithms and structures perform
in large graphs. 

## Programming language Used
- C++
## File Structure
- `/src` contains source code for adjacency list, adjacency matrix, Dijkstra,
and A* search implementations. The data generator is also under this folder.
- `/data` contains simulated graph data:
    - `data.txt` is the large dataset with edges and weights.
    - `test.txt` is a smaller dataset for testing.
    - `data_loc.txt` has location (latitude, longitude) information for each node (large dataset).
    - `test_loc.txt` has location information for the small test dataset.
## Data Generation Rules
We generated random 10,000 nodes and 30,000 edges. 
We also generated latitude and longitude correspond to each node.
Each node has a latitude and longitude assigned randomly within New York City’s range. 
There is no duplicate edges. 

## How to run the program
- To generate data, uncomment the code in `data_generator.cpp`, compile and run it. 
- Check if the data are saved under `data` folder correctly.
- Build the project using your preferred compiler. 
- `main.cpp` runs both Dijkstra and A* on randomly picked start and end nodes. 
- Open `main.cpp` and update if you want to test a different:
  - number of nodes;
  - the file paths to datasets;
  - the start and end nodes to be tested.
- It will print the shortest path found, the total distance, and the time taken. 
- Their performance are compared based on running time.
- If there is no path found between the two nodes, pick another random pair of start and end. 

## Author
- Anirudh Mukund
- Zachary Miguel Allarey
- Macy Yu
