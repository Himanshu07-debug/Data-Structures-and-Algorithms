#include <bits/stdc++.h>
using namespace std;

    bool dfs(int node, int col, int color[], vector<int> adj[]) {

        color[node] = col;

        for (auto it : adj[node]) {

            if (color[it] == -1) {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            } else if (color[it] == col) {
                return false;
            }

        }

        return true;

    }

    bool isBipartite(int V, vector<int> adj[]) {

        int color[V + 1];

        for (int i = 1; i <= V; i++)  color[i] = -1;

        for (int i = 1; i <= V; i++) {

            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }

        }

        return true;
    }


bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

    vector<int> adj[n+1];

    for(auto x : dislikes){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    return isBipartite(n, adj);

}