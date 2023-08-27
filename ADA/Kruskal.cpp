//Krushal Algorithm for finding Minimum Spanning Tree

#include<iostream>
using namespace std;

int main()
{
    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[9][9], parent[9];

    cout << "\nEnter the no. of vertices:- ";
    cin >> n;

    cout << "\nEnter the cost adjacency matrix:- ";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cin >> cost[i][j];

        parent[i] = 0;
    }

    cout << "\nThe edges of Minimum Cost Spanning Tree are:- " << endl;
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u])
            u = parent[u];

        while (parent[v])
            v = parent[v];

        if (u != v)
        {
            cout << "\nEdge " << ne++ << ": (" << a << ", " << b << ") cost:- " << min;
            mincost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    cout << "\nMinimum cost:- " << mincost << endl;
    cout<< "NAME: NANDINI SAIN"<<endl;
    cout<< "ENROLLMENT NO. : A2305221060"<<endl;

    return 0;
}
