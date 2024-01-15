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

bool cycleInUndirectedgraph(int node, vector<vector<int>>& graph, vector<bool>& visited, int parent) {

    visited[node] = true;

    for (int child : graph[node]) {

        if (visited[child] == false){

            if (cycleInUndirectedgraph(child, graph, visited, node)){
                return true;
            }

        } else if (child != parent) {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>>& graph) {

    vector<bool> visited(V, false);

    for (int node = 0; node < V; node++) {

        if (!visited[node]) {
            if (cycleInUndirectedgraph(node, graph, visited, -1))
                return true;
        }

    }

    return false;
    
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    vector<vector<int>> graphaph(V);

    // Add edges to the graphaph
    graphaph[0].push_back(1);
    graphaph[1].push_back(0);
    graphaph[1].push_back(2);
    graphaph[2].push_back(1);
    graphaph[2].push_back(3);
    graphaph[3].push_back(2);

    if (isCycle(V, graphaph))
        cout << "graphaph contains a cycle." << endl;
    else
        cout << "graphaph does not contain a cycle." << endl;

    return 0;
}


