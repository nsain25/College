//Prim Algorithm for finding Minimum Spanning Tree

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int i, j, k, a, b, u, v, n;
    int mincost = 0, cost[9][9], parent[9], key[9];
    bool mstSet[9];

    cout << "\nEnter the no. of vertices: ";
    cin >> n;

    cout << "\nEnter the cost adjacency matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
        parent[i] = -1;
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;

    for (i = 1; i <= n; i++) {
        int minKey = INT_MAX, u;
        for (v = 1; v <= n; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;
        mincost += key[u];

        for (v = 1; v <= n; v++) {
            if (cost[u][v] && !mstSet[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    cout << "\nThe edges of Minimum Cost Spanning Tree are:\n";
    for (i = 2; i <= n; i++) {
        cout << "Edge " << i - 1 << ": (" << parent[i] << ", " << i << ") cost:- " << cost[parent[i]][i] << endl;
    }

    cout << "\nMinimum cost:- " << mincost << endl;
    cout << "NAME: NANDINI SAIN" << endl;
    cout << "ENROLLMENT NO. : A2305221060" << endl;

    return 0;
}
