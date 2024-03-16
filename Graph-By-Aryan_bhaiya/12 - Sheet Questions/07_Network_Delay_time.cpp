#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<pair<int,int>> adj[n+1];

    for(auto x : times){
        adj[x[0]].push_back({x[1], x[2]});
    }

    int S = k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(n+1, INT_MAX);

    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;

            if (dis + w < distTo[v])       
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }

    int mx = 0;

    for(int i=1;i<=n;i++) mx = max(mx, distTo[i]);

    if(mx == INT_MAX) return -1;
    
    return mx;

}