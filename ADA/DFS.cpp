//DFS code for a graph

#include <iostream>
#include <stack>

using namespace std;

// Define the maximum number of vertices
const int MAX_VERTICES = 100;

int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
bool visited[MAX_VERTICES];            // To keep track of visited nodes

// Function to add an edge to the graph
void addEdge(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1; // For an undirected graph
}

// DFS function
void dfs(int start, int vertices) {
    stack<int> s;
    visited[start] = true;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        cout << current << " ";
        s.pop();

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize the graph and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        addEdge(from, to);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth-First Traversal starting from vertex " << startVertex << ": ";
    dfs(startVertex, vertices);
    cout << endl;
    cout << "NAME: NANDINI SAIN" << endl;
    cout << "ENROLLMENT NO. : A2305221060" << endl;

    return 0;
}
