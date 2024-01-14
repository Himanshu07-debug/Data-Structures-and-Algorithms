// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is 
// directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

// For Input output with Visual , Link below -->
// LINK --> https://leetcode.com/problems/map-of-highest-peak/description/

// 1 <= m, n <= 1000


// LOGIC ------------------------------------------------------------------------>>>

// NOTE ->
// Grid diya hai, map bhi bola hai, land, water ki baat, before thinking about DP on grid (becz constraint is suitable for DP) or BS, 
// Think for Graph becz map, land, water jaise matrix ke questions ussi me dekhe hai... 
// Fix krlo, matrix aaya, once only, first think for GRAPHS...

// Its a Interview Problem, so previous pattern se relate krnga... 
// Here, Absolute difference har adj nodes ki 1 chahiye and height maximized krna hai....
// Water ka fix 0 rhnga height, this means iske adjacent wale always 1 rhnge....
// We can take water cells as source and har level pe distance++, differnce parent child ka 1 hi rhnga....

// Multiple water cells hai.... Multi source BFS

// BFS ka intuition aa rha hai.. Same like Problem-01 .. Distance maximized krna hai , Last level tak jayenge....


// Companies -> Google , Microsoft
// See how easy it was, and how much big companies has asked this....


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

vector<vector<int>> highestPeak(vector<vector<int>>& grid) {

    int m = grid.size() , n = grid[0].size();

    queue<pair<int, int>> q;

    vector<vector<bool>> visited(m, vector<bool> (n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int distance = 0;

    vector<vector<int>> ans = grid;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {

        int size = q.size();

        while (size--) {

            auto [x, y] = q.front();
            q.pop();

            ans[x][y] = distance;

            for (auto [dx, dy] : dirs) {

                int i = x + dx, j = y + dy;

                if (i >= 0 && i < m && j >= 0 && j < n) {

                    if(grid[i][j] == 0 && visited[i][j] == false){
                        visited[i][j] = true;
                        q.push({i, j});
                    }

                }
            }
        }
        distance++;
    }   

    return ans;

}