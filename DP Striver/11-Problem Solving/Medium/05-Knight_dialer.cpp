#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;

// Memoization ---------------------------->>>

int fun(int i, int j, int len, vector<vector<int>> &arr, vector<pair<int,int>> &moves, vector<vector<vector<int>>> &dp){

    if(len == 0) return 1;

    if(dp[i][j][len] != -1) return dp[i][j][len];

    int c = 0;

    for(auto [a, b] : moves){

        int x = i + a;
        int y = j + b;

        if(x >= 0 && y >= 0 && x < 4 && y < 3 && arr[x][y] != -1){
            c = (c + fun(x, y, len - 1, arr, moves, dp)) % MOD;
        } 
    }

    return dp[i][j][len] = c;

}

int knightDialer(int n) {

    // Knight moves
    vector<pair<int,int>> moves = { {-2, 1} , {-2, -1}, {2, 1} , {2, -1} , {1, -2}, {-1, -2} , {1, 2} , {-1, 2} };

    vector<vector<int>> arr = { {1, 2, 3} , {4, 5, 6} , {7, 8, 9}, {-1, 0, -1} };

    vector<vector<vector<int>>> dp(4, vector<vector<int>> (3, vector<int>(n+1, -1)));

    int n1 = 4 , m1 = 3;

    int res = 0;

    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){

            if(arr[i][j] != -1){
                res = (res + fun(i, j, n-1, arr, moves, dp)) % MOD;
            }

        }
    }

    return res;
        
}


// Memoization --> Space optimization ..

// We can remove making arr , moves code and can write for each digit, what are the next valid moves.. 
// By this, we only have to keep track of digit and length

// This will not Reduce the TIME & space but will allow us to move 2d DP
// In our code -> 10 possible (i, j) --> 10 * n * 8
// In 2D dp, 10 digits * n 
// Therefore time and Space are Same

int solve(int rem, int digit, vector<vector<int>> &dp, vector<vector<int>> &jumps){

    if(rem == 0) return 1;

    if(dp[rem][digit] != -1) return dp[rem][digit];

    int c = 0;

    for(int nextDigit : jumps[digit]){
        c = (c + solve(rem - 1, nextDigit, dp, jumps))%MOD;
    }

    return dp[rem][digit] = c;

}

int knightDialer(int n) {

    // Knight moves
    vector<vector<int>> jumps = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
    };

    vector<vector<int>> dp(n+1, vector<int>(10, -1));

    int ans = 0;

    for(int i=0;i<10;i++){

        ans = (ans + solve(n-1, i, dp, jumps))%MOD;

    }
        
}

// TABULATION -->
// For all digit -> dp[0][digit] = 1; [ Base case ]
// rem = 1 --> rem =  n-1  && digit = 0 --> digit = 9
// At last, calculate answer -> By adding all dp[n-1][digit]


// SPACE OPTIMIZATION --->
// We are depending on previous states (rem - 1)

// Space optimization for 3d DP --> 
// use len as the first parameter in the recursive calls --> And then optimize them



