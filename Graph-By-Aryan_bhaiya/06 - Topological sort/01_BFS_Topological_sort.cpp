// Topological Sort Defination --> PDF

// BFS Solution of Topological sort is more Intuitive....

// You might be thinking , it is level by level, then why we are checking indegree[child] == 0 before adding child in the Queue ???
// It is Important, see the Image in the folder to Understand...
// Child ko Blindly add nhi kar sakte.. Ho sakta hai uski Dependency bachi ho ....


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



// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> gr[]) {

    // indegree vector
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

    // Topological sort array
    vector<int> tSort;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int node = q.front();
            q.pop();

            // adding in topological vector
            tSort.push_back(node);

            for (auto ne : gr[node]) {

                indegree[ne]--;

                // indegree of node == 0
                if (indegree[ne] == 0)
                    q.push(ne);

            }

        }

    }

    return tSort;

}
