// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance 
// to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

// 1 <= n <= 100

// CONCEPT ---> PDF

// Humko maximize krna hai nearest distance from any water cell to the land cell
// Nearest --> BFS

// APPROACH 1 ->
// Hum each water cell pe jayenge, wha se BFS start krnge and calculate kar lenge uska nearest distance to the land cell...
// In sab me jo distance maximum aayenga, wo ans....

// TIME -> O( n^4 )  [ Worst case me n^2 water cell and sabpe BFS jo ]


// OPTIMIZATION -->
// We will reverse the Idea... Humko each 0 se 1 jna tha... 
// Hum saare 1 se multi - source BFS start krnge to cover all the zeroes....

// No. of level BFS will take to cover all zero -> Maximum distance 

// We are Starting BFS from all 1's at the Starting  ---> Multi Source BFS



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

int maxDistance(vector<vector<int>>& grid) {

    int n = grid.size();
    queue<pair<int, int>> q;

    vector<vector<int>> visited = grid;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 1)
                q.push({i, j});
        }
    }

    if (q.empty() || q.size() == n * n)
        return -1;

    int distance = 0;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {

        int size = q.size();

        while (size--) {

            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {

                int i = x + dx, j = y + dy;

                if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({i, j});
                }

            }

        }

        distance++;

    }
    
    return distance - 1;
}
