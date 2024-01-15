// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells 
// adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is 
// invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

// Return true if any cycle of the same value exists in grid, otherwise, return false.

// Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
// Output: true

// LINK -> https://leetcode.com/problems/detect-cycles-in-2d-grid/description/


// Grid hai, First think can we apply Graph logic

// BFS / DFS on matrix can be applied easily....

// Each character will have their own path... So you have to check visited wla jo parent nhi hai wo same character ka ho


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

bool cycleInUndirectedGraph(int i, int j, vector<vector<char>>& grid, int m, int n, vector<vector<bool>>& visited, vector<pair<int,int>> dir ,
        int a, int b, char c) {

    visited[i][j] = true;

    for(auto [a1, b1] : dir){

        int x = i + a1;
        int y = j + b1;

        if(x >= 0 && x < m && y >=0 && y < n){

            if(grid[x][y] == c){

                if(visited[x][y] == false){

                    if(cycleInUndirectedGraph(x, y, grid, m, n, visited, dir, i, j, c) == true){
                        return true;
                    }


                }
                else if( x != a && y != b )  return true;

            }

        }

    }

    return false;

}


bool containsCycle(vector<vector<char>>& grid) {
        
    int m = grid.size() , n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool> (n, false));

    vector<pair<int,int>> dir = { {1, 0}, {-1, 0} , {0, 1} , {0, -1} };

    for(int i=0;i<m;i++){

        for(int j = 0; j < n ; j++){

            if(visited[i][j] == false){

                if(cycleInUndirectedGraph(i, j, grid, m, n, visited, dir, -1, -1, grid[i][j])){
                    return true;
                }

            }

        }

    }

    return false;

}