#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Define the number of vertices in the graph
#define V 4

// Function to calculate the lower bound of the cost function
int calculateLowerBound(int cost[V][V], vector<bool> visited, int currentCity)
{
    int lb = 0;
    // Calculate the cost of visiting all the unvisited cities
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            int minCost = INT_MAX;
            for (int j = 0; j < V; j++) {
                if (i != j && !visited[j]) {
                    minCost = min(minCost, cost[i][j]);
                }
            }
            lb += minCost;
        }
    }
    // Add the cost of returning to the starting city
    lb += cost[currentCity][0];
    return lb;
}

// Function to solve the TSP using the branch and bound technique
void TSP(int cost[V][V])
{
    // Create a vector to keep track of the visited cities
    vector<bool> visited(V, false);
    visited[0] = true;

    // Create a vector to store the path taken so far
    vector<int> path;
    path.push_back(0);

    // Set the current city and the current cost to 0
    int currentCity = 0;
    int currentCost = 0;

    // Create a priority queue to store the nodes of the search tree
    priority_queue<pair<int, pair<int, vector<int>>>> pq;
    pq.push(make_pair(-calculateLowerBound(cost, visited, currentCity), make_pair(currentCity, path)));

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Get the node with the lowest lower bound
        pair<int, pair<int, vector<int>>> node = pq.top();
        pq.pop();

        // Update the current city and the path taken so far
        currentCity = node.second.first;
        path = node.second.second;
        currentCost = -node.first;

        // Check if all the cities have been visited
        if (path.size() == V) {
            // Add the cost of returning to the starting city
            currentCost += cost[currentCity][0];

            // Print the path and the cost
            cout << "Path: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << "0" << endl;
            cout << "Cost: " << currentCost << endl;
            return;
        }

        // Generate the child nodes of the current node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // Create a new path that includes the current city
                vector<int> newPath(path);
                newPath.push_back(i);

                // Create a new lower bound for the child node
                vector<bool> newVisited(visited);
                newVisited[i] = true;
                int newLowerBound = calculateLowerBound(cost, newVisited, i);

                // Add the child node to the priority queue
                pq.push(make_pair(-(currentCost + cost[currentCity][i] + newLowerBound), make_pair(i, newPath)));
            }
        }
    }
}

// Driver function
int main()
{
    // Define the cost
int cost[V][V] = {{0, 10, 15, 20},
                  {10, 0, 35, 25},
                  {15, 35, 0, 30},
                  {20, 25, 30, 0}};

// Solve the TSP using the branch and bound technique
TSP(cost);

return 0;
}