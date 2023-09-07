#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int INF = INT_MAX;
struct Edge {
    int to;
    int weight;
};
void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    int V = graph.size();
    dist.assign(V, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();
        if (u_dist > dist[u]) continue;
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    cout << "Enter the edges and their weights (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});  // Assuming an undirected graph.
    }
    int start;
    cout << "Enter the source vertex: ";
    cin >> start;
    vector<int> dist;
    dijkstra(graph, start, dist);
    cout << "Shortest distances from vertex " << start << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << ": " << dist[i] << endl;
    }
    cout << "NAME: NANDINI SAIN" << endl;
    cout << "ENROLLMENT NO. : A2305221060" << endl;
    return 0;
}
