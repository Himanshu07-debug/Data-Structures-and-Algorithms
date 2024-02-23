#include<bits/stdc++.h>
using namespace std;

// In case of Square, For any top-most cell (i, j), the possible rightmost cell are only the diagonal elements.
// Therefore, In Square, You can find the Rightmost cell in O(n) and not in O(n^2)

// NAIVE ------------->>
// Leftmost cell selection --> 2 loops for each (i1 , j1) :
// Rightmost cell selection --> 1 loop for this (i2, j2) :
// 2 for loops for calculating the sum of elements from (i1, j1) --> (i2, j2)

// TIME --> O(n ^ 5)


// BETTER ------------->>
// Using Prefix array
// Not It can be solved in O(n^3) --> ACCEPTABLE


// BEST ---------------->>
// Using DP
// dp[i][j] -> No. of valid square submatrices having rightmost cell as (i, j)

// OBSERVATION --------------------->>
// 1. for the first row and for the first column, each cell (i, j), itself will be the one and only square (if cell(i, j) contains 1) that ends 
// at that particular cell i.e. (i, j). So, for the first row and first column, we will just copy the values of the matrix as it is to dp array.

// 2. If arr[i][j] == 1 :
//  we will have to check its three adjacent cells i.e. (i-1, j), (i-1, j-1), and (i, j-1). We will first figure out the minimum number of 
// squares that end at these adjacent cells. And while filling the value for cell(i, j) we will add 1 with that minimum value as the cell (i, j) 
// itself is a square. The formula will be the following:
// dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1

// Ex -> dp[i-1][j] = 2 , dp[i-1][j-1] = 1, dp[i][j-1] = 1
// No. of sqaure submatrix ending at (i-1, j) is 2
// No. of square submatrix ending at (i-1, j-1) is 1
// No. of square submatrix ending at (i, j-1) is 1
// arr[i][j] == 1 is 1 i.e ek square banega..
// Now, 2 adjacent contains value as 1. dp[i-1][j] = 2, this means it also contains no. of sqaure as 1.
// As all the adjacent have a no. of square as 1 ending at their respective indx, considering arr[i][j], the no. of square ending at this cell 
// will be 2

// Otherwise, if the cell(i, j) contains 0, we will also set the value of dp[i][j] as 0.

// TIME --> O(n ^ 2)

int countSquares(vector<vector<int>>& arr) {

    int n = arr.size(), m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (arr[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }

        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    
    return sum;

}
