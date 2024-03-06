#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;

// MIX of Dijkstra + DP ...

// Agar kisi node ka path exist krta hai dest pe then uss node tk aane ke jitne cnt honge, utne hi cnt dest pe aane ke bhi honge..

// cnt[] array as DP
// cnt[i] --> No. of min. path possible till ith node

// it is a Undirected Graph


int countPaths(int n, vector<vector<int>> &roads){

    // Creating an adjacency list for the given graph.
    vector<pair<int, int>> adj[n];

    // Undirected Graph
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Defining a priority queue (min heap). 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initializing the dist array and the cnt array along with their first indices.
    vector<int> dist(n, INT_MAX), cnt(n, 0);
    dist[0] = 0;
    cnt[0] = 1;

    pq.push({0, 0});

    int mod = (int)(1e9 + 7);

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                cnt[adjNode] = cnt[node];
            }
            else if (dis + edW == dist[adjNode])
            {
                cnt[adjNode] = (cnt[adjNode] + cnt[node]) % mod;
            }
        }
    }

    return cnt[n - 1] % mod;
    
}