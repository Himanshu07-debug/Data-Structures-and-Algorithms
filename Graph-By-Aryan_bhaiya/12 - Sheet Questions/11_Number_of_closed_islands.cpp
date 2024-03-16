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

// same question like -- Surrounded Regions

// Here is the code by DFS traversal .. do not doing multiple DFS from boundary cell
// Using single DFS


// For the no. of islands Question --> DFS like flood fill is only the BEST

bool dfs(vector<vector<int>>& g, int i, int j){

    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){
        return false;
    }

    if (g[i][j] == 1){
        return true;
    }

    // mark as Visited
    g[i][j] = 1;

    /* IMPORTANT NOTE: 
    WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
    BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
    */

    bool d1 = dfs(g, i+1, j);
    bool d2 = dfs(g, i, j+1);
    bool d3 = dfs(g, i-1, j);
    bool d4 = dfs(g, i, j-1);

    // if any of them return false i.e there call ends at border
    return d1 && d2 && d3 && d4;

}

int closedIsland(vector<vector<int>>& grid) {

    int res = 0;

    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){

            if (grid[i][j] == 0){
                res += dfs(grid, i, j) ? 1 : 0;
            }

        }
    }

    return res;

}


    