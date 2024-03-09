#include <bits/stdc++.h>
using namespace std;

// DFS , BFS Traversal ---------------------------->>

// For a Graph with n nodes, atleast n-1 edges are required Considering no Cycle to connect all n nodes.

// Agar given no. of edges >= n-1 hai , then we can make a Graph with all nodes connected.

// Min. no. of operation will be ====> ( Number of islands - 1 )

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src){

    visited[src] = true;

    for(int i : adj[src])
        if(!visited[i])
            dfs(adj, visited, i);
        
    
}


int makeConnected(int n, vector<vector<int>>& connections) {
    
    if(connections.size() < n - 1)  return -1;

    vector<vector<int>> adj(n);

    for(auto v : connections)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }

    vector<bool> visited(n, false);

    int islands = 0;

    for(int i=0; i<n; i++)
        if(!visited[i]){
            dfs(adj, visited, i);
            islands++;
        }

    return islands - 1;

}

// TIME ---> O(V + E)



// Disjoint Set ------------------------------>>>

// DSU will make this Question --> A Cake walk

// If same component me hai (u, v), this means Redundant Edge hai Given connections array me yeah wla --> We can use this for Connecting islands.

class DisjointSet {

public:

    vector<int> parent, size;

    DisjointSet(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);

    }


    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int faltu = 0;

        for(auto x : connections){

            if(ds.findUPar(x[0]) == ds.findUPar(x[1])){
                faltu++;
            }
            else{
                ds.unionBySize(x[0], x[1]);
            }

        }

        int components = 0;

        for(int i=0;i<n;i++){
            if(ds.parent[i] == i)  components++;
        }

        if(faltu < components - 1) return -1;

        return (components - 1);
        
    }
};