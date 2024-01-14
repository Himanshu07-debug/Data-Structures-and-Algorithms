// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in 
// this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:
// 1. redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// 2. blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors 
// alternate along the path, or -1 if such a path does not exist.

// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]


// LOGIC --------------------------------------------------->>>>

// Humko shortest path nikalna hai from source node to each of the remaining nodes....
// BFS will help....

// But, Here each cell can be visited twice due to red and blue colors...
// 0th cell 1th cell ko blue edge and red edge dono se approach kar sakta hai if the edges are given....
// Hum therefore, visited me each cell ke liye 2 state add karenge... 0 -> red, 1 -> blue...

// Hum queue me current node and previous color ka track rkhnge, and alternating color edge child possible hai to queue me push krnge...


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

    vector<pair<int,int>> graph[n];

    for(auto x : redEdges){

        graph[x[0]].push_back({x[1], 0});       // 0 for red color

    }

    for(auto x : blueEdges){

        graph[x[0]].push_back({x[1], 1});       // 1 for blue color

    }

    vector<vector<bool>> visited(n, vector<bool>(2, false));

    vector<int> dist(n, -1);

    queue<pair<int,int>> q;

    // (node, color)
    q.push({0, -1});           
    // source will not have any color

    visited[0][0] = true;
    visited[0][1] = true;

    int distance = 0;

    while(!q.empty()){

        int z = q.size();

        for(int i=0;i<z;i++){

            auto [node, color] = q.front();
            q.pop();

            if(dist[node] == -1)   
                dist[node] = distance; 

            for(auto [x, col] : graph[node]){

                if( col != color && visited[x][col] == false){
                    visited[x][col] = true;
                    q.push({x, col});
                }

            }

        }

        distance++;

    }

    return dist;

}