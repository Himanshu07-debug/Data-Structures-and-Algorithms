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

void bfsOfGraph(int src, vector<int>& vis, vector<vector<int>>& gr) {

    queue<int> q;
    q.push(src);

    vis[src] = 1;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int child : gr[cur]) {

            if (vis[child] == 0) {
                q.push(child);
                vis[child] = 1;
            }

        }

    }

}

int main() {

    int n, m;
    cin >> n >> m;

    // Graph Nodes are from 0 to n-1
    vector<vector<int>> gr(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<int> vis(n, 0);

    bfsOfGraph(0, vis, gr);
    
}