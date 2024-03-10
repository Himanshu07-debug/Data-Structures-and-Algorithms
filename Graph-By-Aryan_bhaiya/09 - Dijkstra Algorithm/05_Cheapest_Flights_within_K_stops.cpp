#include <bits/stdc++.h>
using namespace std;

// In this Form of Dijkstra, You have to find the Shortest path from src to dest but with a condition of K.

// Main Idea in this Question -->




int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {

    vector<pair<int,int>> gr[n];

    for(auto x : arr){
        gr[x[0]].push_back({x[1], x[2]});
    }


    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

    vector<int> stops(n, 1e9);

    // {dist, node, stops}
    pq.push({0, src, 0 });
    stops[src] = 0;

    while(!pq.empty()){

        vector<int> tmp = pq.top();
        pq.pop();

        int dist = tmp[0];
        int node = tmp[1];
        int step = tmp[2];

        if(step > stops[node] || step > k + 1) continue;

        stops[node] = step;

        if(node == dst) return dist;

        for(auto [a, b] : gr[node]){

            pq.push({dist + b, a, step + 1});

        }

    }

    return -1;

}

// TIME --> E * K * log(E * k) + V [ each edge can be visited atmost K times ]
// SPACE --> E*K + V



// BFS ------------------------->>>

// Go Step by step and Try to Complete all of the K stops.

int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {

    vector<pair<int,int>> gr[n];

    for(auto x : arr){
        gr[x[0]].push_back({x[1], x[2]});
    }

    vector<int> dist(n, 1e9);
    queue<pair<int,int>> q;

    // {node, dist}
    q.push({src, 0});
    dist[src] = 0;

    int stops = 0;

    while(stops < k + 1 && !q.empty()){

        int z = q.size();

        for(int i=0;i<z;i++){

            auto [node, distance] = q.front();
            q.pop();

            for(auto [a, b] : gr[node]){

                if(distance + b < dist[a]){
                    dist[a] = distance + b;
                    q.push({a, dist[a]});
                }

            }

        }

        stops++;

    }    

    if(dist[dst] == 1e9) return -1;

    return dist[dst];

}

// TIME --> O(V + E*K)

