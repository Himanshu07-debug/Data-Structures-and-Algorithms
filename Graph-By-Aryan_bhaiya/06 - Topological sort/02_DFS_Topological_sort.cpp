// IDEA -> Go deeper and deeper and while returning back i.e when the node do not have any child to call, push that node to the vector...

// How we came to this IDEA ??? No matter, aap konse node se start kar rhe ho DFS, there is some similarity in the ending nodes of each path...


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


void dfs(int node, vector<int>& tSort, vector<bool>& vis, vector<int> gr[]) {

    vis[node] = true;

    for (auto ne : gr[node]) {
        if (vis[ne] == false)
            dfs(ne, tSort, vis, gr);
    }

    // Adding after the call
    tSort.push_back(node);

}

vector<int> topoSort(int V, vector<int> gr[]) {

    vector<bool> vis(V, 0);
    vector<int> tSort;

    for (int node = 0; node < V; node++) {
        if (vis[node] == false)
            dfs(node, tSort, vis, gr);
    }

    // Reversing vector
    reverse(tSort.begin(), tSort.end());

    return tSort;

}

