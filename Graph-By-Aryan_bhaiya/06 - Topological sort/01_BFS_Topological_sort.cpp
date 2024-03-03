// Topological Sort Defination --> 
// In computer science, a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for
//  every directed edge (u,v) from vertex u to vertex v, u comes before v in the ordering.


// You only have to worry about ki Parent ke phle child na aaye.. Otherwise valid ordering bhut saari ho skti hai

// Ex -> Graph ==> 0 -> { 2, 3 } , 1 -> { 3, 4 } .. 0 and 1 both have indegree 0
// Valid Topological sort --> 
// 0 1 2 3 4 
// 1 4 0 3 2
// 0 2 1 4 3
// 0 1 3 2 4
// ....

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

        while (sz--) {             // no need to maintain this level as this is not Distance output question

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
