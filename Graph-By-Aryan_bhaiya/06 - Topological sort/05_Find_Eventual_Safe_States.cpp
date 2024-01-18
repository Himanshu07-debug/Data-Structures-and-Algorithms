// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph 
// where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a 
// terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// CONSTRAINT ------------->>>
// n == graph.length
// 1 <= n <= 10^4
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 10^4]



// LOGIC ----------------------------------------------------------------------------->>>>>>


// This is Same like Topological sort but yha pe Outdegree ki baat hui hai....
// So, hume Outdegree calculate krnge each node ki... Ek reverse graph baneage jha node will store their incoming nodes given graph se...
// Now outdegree 0 wale nodes ko add krnge and then unko remove krnge
// Remove kiye to wo nodes jinka edge inpe tha wo unke outdegree 1 se reduce honga... If outdegree 0 hua nodes ka add kar denge queue me...
// Child of nodes i.e the list of incoming nodes is stored in reverse graph...



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

vector<int> eventualSafeNodes(vector<vector<int>>& edges) {

    int n = edges.size();

    vector<int> graph[n];

    vector<int> outdegree(n,0);

    for(int i=0;i<n;i++){

        outdegree[i] = edges[i].size();

        for(int x : edges[i]){
            graph[x].push_back(i);
        }

    }

    vector<int> ans;

    queue<int> q;

    for(int i=0;i<n;i++) {
        if(outdegree[i] == 0) q.push(i);
    }


        vector<int> tSort;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int node = q.front();
            q.pop();

            // adding in topological vector
            tSort.push_back(node);

            for (auto ne : graph[node]) {

                outdegree[ne]--;

                // indegree of node == 0
                if (outdegree[ne] == 0)
                    q.push(ne);

            }

        }

    }

    sort(tSort.begin(), tSort.end());

    return tSort;

        
}



