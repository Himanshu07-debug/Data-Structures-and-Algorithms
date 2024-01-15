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

// you can assume Path visited array as Recursive call stack holding the current DFS traversal nodes....

// Function to detect cycle in a directed graph.
bool cycleInDirectedGraph(int node, vector<int> gr[], vector<bool>& visited, vector<bool>& pathVisited) {

    visited[node] = true;
    pathVisited[node] = true;

    for (auto child : gr[node]) {

        if (visited[child] == false) {

            if (cycleInDirectedGraph(child, gr, visited, pathVisited))
                return true;
        
        } else if (pathVisited[child] == true) {
            return true;
        }

    }

    // Backtrack
    pathVisited[node] = false;
    
    return false;

}


bool isCyclic(int V, vector<int> gr[]) {

    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);

    for (int i = 0; i < V; i++) {

        if (visited[i] == false)
            if (cycleInDirectedGraph(i, gr, visited, pathVisited))
                return true;
        
    }

    return false;
}