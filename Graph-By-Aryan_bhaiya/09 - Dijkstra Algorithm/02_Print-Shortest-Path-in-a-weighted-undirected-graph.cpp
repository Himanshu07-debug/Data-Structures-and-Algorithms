#include <bits/stdc++.h>
using namespace std;

// For Printing the Path , you have to keep track of the parents of the each node.

// Make a new parent[] array and initalize all with -1

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(V + 1, INT_MAX);

    vector<int> parent(V + 1, -1);

    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];

            if (dis + w < distTo[v])     
            {
                distTo[v] = dis + w;
                parent[v] = node;
                pq.push({dis + w, v});
            }
        }
    }

    if(distTo[V] == 1e9) return {-1};

    vector<int> path;

    int curr = V;

    path.push_back(V);

    while(parent[curr] != -1){
        path.push_back(parent[curr]);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    return path;

}

// TIME --> O(E * logV) + O(V) [ path loop can max run for all vertices --> Linear path ]
