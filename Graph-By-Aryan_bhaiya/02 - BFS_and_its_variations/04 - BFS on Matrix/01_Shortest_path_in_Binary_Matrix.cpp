// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// 1. All the visited cells of the path are 0.
// 2. All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

// NOTE -> The length of a clear path is the number of visited cells of this path.

// Input: grid = [[0,1],[1,0]]
// Output: 2
// (0,0) -> (1,1)


// LOGIC ---------------------------------------->>>


// We are Spreading from the current cell in all 8 directions...
// Just like poison kisi cell se spread ho rha hai valid cells se destination cell pe...

// Spreading --> Same as Breadth   +  Shortest path   -->    BFS 

// Shortest me BFS hamesha help krta hai...
// Path ka length no. of cells hai --> no. of arrows + 1
// Observe, You can consider each arrow as a level .... 
// Min. no levels me i.e Sabse phle jo destination pe pahuchaega, That will be the Shortest Path.....


// Detailed Explanation in --> PDF

// Why we not tried for DP on Grid here ????
// Here, there are 8 directions possible here...
// Let State -> Shortest path from (0,0) to (i,j) 
// To upar wale to prepare ho jayenge base case, niche wale direction ke cell ka kya... Wo to abhi Compute nhi hue hai...

// Same if Considered State -> Shortest path from (i, j) -> (m-1, n-1)

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

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int m = grid.size() , n = grid[0].size();

    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

    // For all 8 directions
    int dir[8][2] = { {0, 1} , {0, -1} , {1, 0} , {-1, 0} , {1, -1} , {-1, 1}, {-1, -1} , {1, 1} };

    vector<vector<bool>> visited(m, vector<bool> (n, false));

    visited[0][0] = true;

    queue<vector<int>> q;

    q.push({0, 0});

    // length of clear path
    int ans = 0;

    while(!q.empty()){

        int z = q.size();

        for(int i = 0; i < z ; i++){

            vector<int> curr = q.front();
            q.pop();

            // Reached to the destination
            if(curr[0] == m-1 && curr[1] == n-1){
                return ans + 1;   // no. of arrows + 1 ==> no. of cells
            }

            // Pure ek level ke liye humko sirf ek baar add krna hai

            for(int j=0; j<8;j++){

                int x =  curr[0] + dir[j][0];
                int y =  curr[1] + dir[j][1];

                if(x >= 0 && y >=0 && x < m && y < n){

                    if(visited[x][y] == false && grid[x][y] == 0){

                        visited[x][y] = true;

                        q.push({x, y});

                    }

                }

            }

        }

        ans += 1;

    }

    return false;
  
}

// OPTIMIZATION --> Pair is Faster than vector, use pair in Queue

// Agar Interviewer Input ko change karna allow krta hai, You can use Original matrix and -1 value for visited check

