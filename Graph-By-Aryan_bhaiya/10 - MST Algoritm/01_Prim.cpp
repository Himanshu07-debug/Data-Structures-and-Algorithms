#include <bits/stdc++.h>
using namespace std;

// Return an array consisting of edges in the MST and sum of all edges of MST.

// If sum is only asked, You can do it by only keeping {len, node} in PQ

void MST(vector<pair<int,int>> adj[] , int n){

    vector<pair<int,int>> edges;

    vector<int> visited(n, -1);

    int sum = 0;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    // {edge_length, node, parent}

    pq.push({0, {0, -1}});

    while(!pq.empty()){

        int len = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if(visited[node] != -1) continue;

        visited[node] = 1;

        sum += len;

        if(parent != -1){
            edges.push_back({parent, node});
        }

        for(auto [a, b] : adj[node]){

            if(visited[a] == -1){
                pq.push({b, {a, node}});
            }

        }

    }

    cout << sum << endl;

    for(auto [a , b] : edges){
        cout << a << "-->" << b << endl;
    }


}