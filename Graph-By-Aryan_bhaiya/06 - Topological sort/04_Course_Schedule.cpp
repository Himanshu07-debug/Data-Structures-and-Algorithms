// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites 
// where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


// Here, prerequisites dependency in graph ki feel de rha hai. Also Jobs ek ordered me honge, uski bhi feel de rha hai...
// Jobs, Ordering -> Topological Sort

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
bool isCyclic(int V, vector<int> graph[]) {

    vector<int> indegree(V, 0);

    for (int node = 0; node < V; node++) {
        for (auto ne : graph[node]) {
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

            for (auto ne : graph[node]) {

                indegree[ne]--;

                if (indegree[ne] == 0)
                    q.push(ne);

            }

        }

    }

    // No. of nodes != topological vector size
    return (tSort.size() != V);

}

bool canFinish(int n, vector<vector<int>>& prerequisites) {

    vector<int> graph[n];

    for(auto x : prerequisites){

        graph[x[1]].push_back(x[0]);

    }

    // Cycle Detected
    if(isCyclic(n, graph)) return false;
    else return true;
        
}


