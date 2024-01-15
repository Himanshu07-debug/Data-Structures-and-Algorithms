// Topological sort can only be applied on a Directed Acyclic Graph...

// Agar cycle hai, So there will be a moment, when kisi bhi node ki indegree 0 nhi hongi and nodes Queue me add nhi honge.. Becz cycle me present 
// nodes me kisi ki bhi indegree 0 nhi rhti....

// See PDF for visualization .....

// So agar Topological Vector me Pure nodes nhi aa rhe, Cycle is there...

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

    // Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> gr[]) {

    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++) {
        for (auto ne : gr[node]) {
            indegree[ne]++;
        }
    }

    queue<int> q;

    for (int node = 0; node < V; node++) {
        if (indegree[node] == 0)
            q.push(node);
    }

    vector<int> tSort;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int node = q.front();
            q.pop();

            tSort.push_back(node);

            for (auto ne : gr[node]) {

                indegree[ne]--;

                if (indegree[ne] == 0)
                    q.push(ne);

            }

        }

    }

    // No. of nodes != topological vector size
    return (tSort.size() != V);

}
