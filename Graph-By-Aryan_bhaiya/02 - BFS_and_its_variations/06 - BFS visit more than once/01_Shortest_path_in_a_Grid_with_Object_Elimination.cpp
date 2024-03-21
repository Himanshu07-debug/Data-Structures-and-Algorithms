// GOOGLE INTERVIEW QUESTION ---------------------------------------------->>


// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from 
// and to an empty cell in one step.

// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can 
// eliminate at most k obstacles. If it is not possible to find such walk return -1.

// Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
// Output: 6
// Explanation: 
// The shortest path without eliminating any obstacle is 10.
// The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

// Constraint -> 1 <= m, n <= 40,   grid[0][0] == grid[m - 1][n - 1] == 0


// shortest path --> BFS

// NOTE -> Here Each cell pe diff. states ho sakte hai based on the elimination power values 
//         So ek 3rd parameter bhi rhnga BFS me for Elimination power values....

// Here, it is a type of BFS where visiting to the same cell is allowed more than once based on some conditions on Questions


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

int shortestPath(vector<vector<int>>& grid, int k) {

    int m = grid.size() , n = grid[0].size();

    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));

    queue<vector<int>> q;

    q.push({0, 0, k});

    visited[0][0][k] = true;

    int dir[4][2] = { {0, 1} , {0, -1} , {1, 0} , {-1, 0} };

    int steps = 0;

    while(!q.empty()){

        int z = q.size();

        for(int i=0;i<z;i++){

            vector<int> curr = q.front();
            q.pop();

            if(curr[0] == m-1 && curr[1] == n-1) return steps;

            for(int j=0;j<4;j++){

                int x = curr[0] + dir[j][0];
                int y = curr[1] + dir[j][1];

                int power = curr[2];

                if(x >= 0 && x < m && y >= 0  && y < n){

                    if(grid[x][y] == 0 && visited[x][y][power] == false){

                        visited[x][y][power] = true;
                        q.push({x, y, power});

                    }
                    else if(grid[x][y] == 1 && power > 0 && visited[x][y][power - 1] == false){
                        visited[x][y][power - 1] = true;
                        q.push({x, y, power - 1});
                    }

                }

            }

        }

        steps++;


    }

    return -1;



}