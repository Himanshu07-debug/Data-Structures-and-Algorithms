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


void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited, int n, int m, int &sum){

    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j] == true ) return;

    sum++;
    visited[i][j] = true;

    dfs(i-1, j, grid, visited, n, m, sum);
    dfs(i+1, j, grid, visited, n, m, sum);
    dfs(i, j+1, grid, visited, n, m, sum);
    dfs(i, j-1, grid, visited, n, m, sum);

}


int maxAreaOfIsland(vector<vector<int>>& grid) {
        
    int n = grid.size(), m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool> (m, false));

    int mx = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] == 1 && visited[i][j] == false){

                int sum = 0;
                dfs(i, j, grid, visited, n, m, sum);

                mx = max(mx, sum);

            }

        }
    }

    return mx;

}