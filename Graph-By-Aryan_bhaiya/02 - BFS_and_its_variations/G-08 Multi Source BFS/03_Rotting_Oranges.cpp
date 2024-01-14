// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1


// LOGIC ------------------------------------------------>>>

// Min. no of minutes -> BFS
// Also grid me 2 i.e rotten oranges multiple cells pe ho sakte hai, Wo simultaneously apne adjacent wale fresh oranges ko rotten krnge...
// So, Humko Multi source BFS krna padega......


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


int orangesRotting(vector<vector<int>>& grid) {

    int m = grid.size() , n = grid[0].size();

    queue<pair<int, int>> q;

    vector<vector<int>> visited = grid;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 2)
                q.push({i, j});
        }
    }

    int time = 0;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {

        int size = q.size();

        while (size--) {

            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {

                int i = x + dx, j = y + dy;

                if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                    visited[i][j] = 2;
                    q.push({i, j});
                }
            }
        }
        time++;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(visited[i][j] == 1) return -1;

        }
    }

    if(time > 0) time--;

    return time;

}