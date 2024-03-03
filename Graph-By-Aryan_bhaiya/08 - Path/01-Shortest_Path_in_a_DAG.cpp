#include <bits/stdc++.h>
using namespace std;

// In Dijkstra, TIME is O(V^2) and optimized one --> O((V + E) * logV)

// Can We do even more better taking the advantage of the fact i.e the Graph is DAG ??
// In DAG, Topological sort can help.. 
// Becz in topo sort, all the nodes before the required nodes i.e parents will be processed to give the min. distance to the required node..

// Getting min node in Dijkstra --> Reduces to O(1) in DAG

// Topo sort ke liye DFS used becz Code chotta hai

class Solution {
public:

    void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {

        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                findTopoSort(it.first, vis, st, adj);
            }
        }

        st.push(node);

    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){

        vector<pair<int, int>> adj[N];

        int src = 0;

        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        int vis[N] = {0};

        stack<int> st;

        // DFS returns topological sort in Reverse order.. Using Stack so that no need to reverse
        for (int i = 0; i < N; i++)
            if (!vis[i])
                findTopoSort(i, vis, st, adj);
        

        vector<int> dist(N, 1e9);
        dist[src] = 0;

        while (!st.empty()){

            int node = st.top();
            st.pop();

            // Going through all the parents
            for (auto it : adj[node]) {
                if (dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }

        for (int i = 0; i < dist.size(); ++i) {
            if (dist[i] == 1e9)dist[i] = -1;
        }

        return dist;

    }

};

// If in the Same question, if Longest is asked, make all edge weights as -ve and apply the Shortest Path Idea, At last, remove the - sign