#include <bits/stdc++.h>
using namespace std;


// Adjacency Matrix ------------------->>

int main()
{

    int n, m;
    cin >> n >> m;

    // n nodes and m edges in total


    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }

    return 0;
    
}

// Adjacency List ( BEST ) --------------------->>

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;

}

// If Weighted Directed Graph --------------------------->>

// vector< pair <int,int> > adjList[n+1];

// cin >> u >> v >> wt
// adj[u].push_back({v, wt});
// adj[v].push_back({u, wt});