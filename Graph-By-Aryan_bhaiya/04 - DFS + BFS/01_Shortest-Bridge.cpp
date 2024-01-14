// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
// You may change 0's to 1's to connect the two islands to form one island.
// Return the smallest number of 0's you must flip to connect the two islands.

// Input: grid = [[0,1],[1,0]]
// Output: 1


// More Inputs and Explanation -> PDF


// LOGIC ----------------------------------------------->>>

// We have to find the Shortest Bridge between the Two Islands.....
// We will find one island by DFS / BFS

// Shortest -> BFS
// Now from founded island, we will calculate the distance to reach to the other island... 
// Lekin BFS ke liye source node chahiye, Wo kaise select kronge... founded island ka konsa node nearest hai second island se, how to decide ??

// NAIVE -> Applying BFS on each node of founded island ---> O(n^4)
// OPTIMIZED -> We will use Multi source BFS variation -> All 1's of founded island se BFS chalu

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

// DFS for marking the first island as visited
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int i, int j, vector<vector<int>>& dirs) {

    // Base case
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == true || grid[i][j] == 0)
        return;
    
    visited[i][j] = true;
    q.push({i, j});

    for (auto& dir : dirs)
        dfs(grid, visited, q, i + dir[0], j + dir[1], dirs);
    
}

int shortestBridge(vector<vector<int>>& grid) {

    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pair<int, int>> q;
    bool found = false;

    // Adding multi sources to the queue by calling DFS for an island
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                dfs(grid, visited, q, i, j, dirs);
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    int step = 0;

    while (!q.empty()) {

        int size = q.size();

        for(int z =0; z<size; z++){

            auto cur = q.front();
            q.pop();

            for (auto& dir : dirs) {

                int i = cur.first + dir[0];
                int j = cur.second + dir[1];

                if (i >= 0 && j >= 0 && i < m && j < n && visited[i][j] == false) {

                    // Got another island, return 
                    if (grid[i][j] == 1) {
                        return step;
                    }
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        step++;
    }
    
    return -1;
}