#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {

    vector<pair<int,int>> gr[n];

    for(auto x : arr){
        gr[x[0]].push_back({x[1], x[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>,
                greater<vector<int>>> pq;

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    pq.push({0, src, 0});

    while(!pq.empty()){

        auto x = pq.top();

        int d = x[0] , node = x[1] , stop = x[2];

        pq.pop();

        for(auto [a, b] : gr[node]){

            if(dist[a] > dist[node] + b){

                if(a == dst){
                    dist[a] = dist[node] + b;
                    pq.push({dist[a], a, stop});
                }
                else if(stop < k){
                    dist[a] = dist[node] + b;
                    pq.push({dist[a], a, stop + 1});
                }

            }

        }

    }

    if(dist[dst] == 1e9) return -1;

    return dist[dst];


}