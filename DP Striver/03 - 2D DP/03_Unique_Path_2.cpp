// Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell.
//  A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to 
// cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.

// 0 0 0 
// 0 -1 0 
// 0 0 0
// ANS ==> 2 ways 
// (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
// (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)


// Memoization ----->

#include <bits/stdc++.h> 
using namespace std;

long long MOD = 1e9 + 7;

int count(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &mat){

	if( i == 0 && j == 0) return 1;

	if( i < 0 || j < 0 || mat[i][j] == -1) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int left = count(i, j - 1, dp, mat);
	int up = count(i-1, j, dp, mat);

	return dp[i][j] = (left + up) % MOD;

}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int> (m, -1));

    return count(n-1, m-1, dp, mat);

}


// Iterative --------------------------------------->>

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	// Write your code here.

	vector<vector<int>> dp(n, vector<int> (m, 0));

	dp[0][0] = 1;

	for(int i=0;i<n;i++){
		for(int j = 0; j< m ;j++){

			if( i == 0 && j == 0) continue;

            if(mat[i][j] == -1) continue;

            int up = 0;
            int left = 0;

			if(i - 1 >= 0) up = dp[i-1][j];

			if(j - 1 >= 0) left = dp[i][j-1];

            dp[i][j] = (up + left) % MOD;

		}
	}

	return dp[n-1][m-1];

}


// SPACE OPTIMIZATION ----------------------------------->>>

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	// Write your code here.

	vector<int> prev(m, 0);

	for(int i=0;i<n;i++){

		vector<int> curr(m, 0);

		for(int j = 0; j< m ;j++){

			if(i == 0 && j == 0) curr[j] = 1;
            else if(mat[i][j] == -1) curr[j] = 0;
			else{

				int up = 0, left = 0;

				if(i - 1 >= 0) up = prev[j];

				if(j - 1 >= 0) left = curr[j-1];

				curr[j] = (up + left) % MOD;

			}
		}

		prev = curr;
		
	}

	return prev[m-1];

}
