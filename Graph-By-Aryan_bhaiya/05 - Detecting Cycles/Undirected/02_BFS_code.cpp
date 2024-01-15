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

bool cycleInUndirectedgraph(int node, vector<vector<int>>& graph, vector<bool>& visited){

    queue<pair<int,int>> q;     // (vertex, parent of vertex)

    q.push({node, -1});

    visited[node] = true;

    while(!q.empty()){

        auto [curr, parent] = q.front();
        q.pop();

        for(int child : graph[curr]){

            if(visited[child] == false){
                visited[child] = true;
                q.push({child, parent});
            }
            else if(child != parent){
                return true;
            }

        }

    }

    return false;

} 

bool isCycle(int V, vector<vector<int>>& graph) {

    vector<bool> visited(V, false);

    for (int node = 0; node < V; node++) {

        if (!visited[node]) {
            if (cycleInUndirectedgraph(node, graph, visited))
                return true;
        }

    }

    return false;
    
}
