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


// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
// The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
// Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
// The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.


// Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
// Output: 0
// Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).


bool isSafe(vector<vector<int>> &pre, int safeDist, vector<pair<int,int>> &dir){

    int n = pre.size();

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if(pre[0][0] < safeDist){
        return false;
    }

    q.push({0, 0});
    vis[0][0] = 1;

    while(!q.empty()){

        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        if(a == n-1 && b == n-1) return true;

        for(auto [x, y] : dir){

            int c = a + x;
            int d = b + y;

            if(c >= 0 && d >= 0 && c < n && d < n){

                if(pre[c][d] < safeDist || vis[c][d] == 1) continue;

                vis[c][d] = 1;

                q.push({c, d});

            }

        }

    }

    return false;

}


int maximumSafenessFactor(vector<vector<int>>& arr) {

    int n = arr.size();

    queue<pair<int,int>> q;

    vector<vector<int>> pre(n, vector<int>(n, -1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                q.push({i, j});
                pre[i][j] = 0;
            }
        }
    }

    vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int dist = 0;

    while(!q.empty()){

        int z = q.size();

        for(int i=0;i<z;i++){

            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            pre[a][b] = dist;

            for(auto [x, y] : dir){

                int c = a + x;
                int d = b + y;

                if(c >= 0 && d >= 0 && c < n && d < n){

                    if(pre[c][d] == -1){
                        q.push({c, d});
                    }

                }

            }

        }

        dist++;

    }

    int l = 0, h = dist - 1;

    int ans = 0;

    while(l <= h){

        int mid = l + (h - l)/2;

        if(isSafe(pre, mid, dir)){
            ans = mid;
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }

    }

    return ans;
        
}