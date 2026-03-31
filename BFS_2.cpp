#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS
void BFS(int startNode, const vector<vector<int>>& adjList)
{
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    queue<int> q;                                // Queue for BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop(); // Dequeue the current node
        cout << currentNode << " "; // Process the node

        // Traverse all adjacent nodes
        for (size_t i = 0; i < adjList[currentNode].size(); ++i)
        {
            int neighbor = adjList[currentNode][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Enqueue the neighbor
            }
        }
    }
    cout << endl;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (if the graph is undirected)
    }

    int startNode;
    cout << "Enter the start node for BFS: ";
    cin >> startNode;

    // Perform BFS
    BFS(startNode, adjList);

    return 0;
}

