// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell 
// in the first row to any cell in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular 
// cell (row, col), we can move in three directions i.e.
// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)

// 4 4
// 1 2 10 4
// 100 3 2 1
// 1 1 20 2
// 1 2 2 1
// The maximum path sum will be 2->100->1->2, So the sum is 105(2 + 100 + 1 + 2).

// 1 <= N <= 100
// 1 <= M <= 100
// -10^4 <= matrix[i][j] <= 10^4


// LOGIC ----------------------------------------------------->>>

// Here we have Variable st. point and Variable ending pt. -> So koi bhi way se krlo recursion -> Striver way or Reverse Striver way

// To generate all possible paths we will use recursion.

// RECURSION ----------------->>

// TIME -> O(3 ^ n)

// SPACE -> O(n) + O(n * n)



// MEMOIZATION ---------------------------------->>>

// Reverse Striver way --> 

// In Recursive way, Hume Last row ke saare elements se one by one call krna honga, Kyuki ek element ko ending pt. consider kiye, to baaki
// element skip ho jayenge, so sabke liye call and take the max

#include <bits/stdc++.h> 
using namespace std;

int path(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp, int n, int m){

    if(j < 0 || j >= m) return -1e9;   

    // Q.s -> Why you are not Returning INT_MIN ???
    // ANS -> Agar arr[i][j] -ve hua to INT_MIN se add hoke overflow ho jayega.. To avoid this, we are returning -1e9, not INT_MIN         

    if(i == n-1) return arr[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int p1 = arr[i][j] + path(i+1, j, arr, dp, n, m);
    int p2 = arr[i][j] + path(i+1, j+1, arr, dp, n, m);
    int p3 = arr[i][j] + path(i+1, j-1, arr, dp, n, m);

    return dp[i][j] = max(p1, max(p2, p3));

}


int getMaxPathSum(vector<vector<int>> &arr)
{
    //  Write your code here.

    int n = arr.size(), m = arr[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    int ans = INT_MIN;

    for(int i = 0; i < m;i++){

        int mx = path(0, i, arr, dp, n, m);

        ans = max(ans, mx);

    }

    return ans;

}


// STRIVER WAY ------------------->>

// Prefer this, becz Iterative easy lagta hai likhna isase.. Aache se visualize hota hai

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    // Base Conditions
    if (j < 0 || j >= m) return -1e9;

    if (i == 0)     return matrix[0][j]; 
    
    if (dp[i][j] != -1)     return dp[i][j]; 
    
    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);
    
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));

}


int getMaxPathSum(vector<vector<int>> &matrix) {

    int n = matrix.size(); 
    int m = matrix[0].size(); 
    
    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    
    int maxi = INT_MIN; 
    
    // Iterate through each cell in the first row to find the maximum path sum starting from each of them
    for (int j = 0; j < m; j++) {

        int ans = getMaxUtil(n - 1, j, m, matrix, dp); 

        maxi = max(maxi, ans); 
    }
    
    return maxi;

}


// ITERATIVE ------------------------->>

// Isme one by one call krne ki no need, last row ke saare element consider honge....


int getMaxPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // 0th row (BASE)
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {

            // Up direction
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = -1e9;

            if (j - 1 >= 0) {
                leftDiagonal = matrix[i][j] + dp[i - 1][j - 1];
            }

            int rightDiagonal = -1e9;
            if (j + 1 < m) {
                rightDiagonal = matrix[i][j] + dp[i - 1][j + 1];
            }

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));

        }
    }

    // Last row
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }

    // The maximum path sum is the maximum value in the last row
    return maxi;

}


// SPACE OPTIMIZATION ------------------------------>>

int getMaxPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix

    vector<int> prev(m, 0); // Represents the previous row's maximum path sums 

    // first row (base condition)
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {

        vector<int> curr(m, 0); 

        for (int j = 0; j < m; j++) {

            int up = matrix[i][j] + prev[j];

            int leftDiagonal = -1e9;

            if (j - 1 >= 0) {
                leftDiagonal = matrix[i][j] + prev[j - 1];
            }

            int rightDiagonal = -1e9;
            if (j + 1 < m) {
                rightDiagonal = matrix[i][j] + prev[j + 1];
            }

            curr[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        // Update the 'prev' array with the values from the 'cur' array for the next iteration
        prev = curr;
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }

    // The maximum path sum is the maximum value in the last row of 'prev'
    return maxi;
    
}
