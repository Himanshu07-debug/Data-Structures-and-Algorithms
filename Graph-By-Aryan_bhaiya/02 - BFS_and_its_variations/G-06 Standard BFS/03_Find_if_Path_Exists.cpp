// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are 
// represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
// Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 -→ 1 --→ 2
// - 0 -→ 2


// Constraint -> 1 <= n <= 2 * 10^5


// LOGIC -> 
// We can use Simply BFS traversal to check the path exists or not..

// DFS can also be used....


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

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    vector<int> graph[n];

    int m = edges.size();

    for(int i=0;i<m;i++){

        int u = edges[i][0], v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    vector<int> visited(n, -1);

    visited[source] = 1;

    queue<int> q;

    q.push(source);

    while(!q.empty()){

        int curr = q.front();
        q.pop();

        for(int x : graph[curr]){

            if(visited[x] == -1){
                visited[x] = 1;
                q.push(x);
            }

        }

    }

    return (visited[destination] == 1);

}