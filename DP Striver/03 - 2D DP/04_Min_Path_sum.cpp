// We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such 
// that there is a minimum cost past that we select.
// At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the
//  given matrix.

// 5 9 6
// 11 5 2
// Ans -> 21
// path with minimum value is (0,0) -> (0,1) -> (1,1) -> (1,2). And the sum along this path is 5 + 9 +5 + 2 = 21. So the ans is 21.

// We are aware that ki if yeah 2 movements allowed hai, there will be Overlapping Subproblems.

// Memoization ------------------------------>>>

#include <bits/stdc++.h>
using namespace std;

int path(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){

	if( i == 0 && j == 0) return grid[i][j];

	if( i < 0 || j < 0 ) return INT_MAX;

	if(dp[i][j] != -1) return dp[i][j];

	int left = grid[i][j] + path(i, j - 1, dp, grid);
	int up = grid[i][j] + path(i-1, j, dp, grid);

	return dp[i][j] = min(left, up);

}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return path(n-1, m-1, dp, grid);

}

// ITERATIVE -------------------------------------->>

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size(), m = grid[0].size();

	vector<vector<int>> dp(n, vector<int> (m));

	for(int i=0;i<n;i++){

		for(int j = 0; j < m ;j++){

			if( i == 0 && j == 0) dp[i][j] = grid[i][j];
            else{

                int up = 1e9;
                int left = 1e9;
                // Initialize with out of bound values

                if(i - 1 >= 0) up = grid[i][j] + dp[i-1][j];

                if(j - 1 >= 0) left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);

            }

		}
	}

	return dp[n-1][m-1];

}

// SPACE OPTIMIZATION is also Possible