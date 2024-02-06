// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move 
// to either index i or index i + 1 on the next row.

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11

// CONSTRAINT --> 
// 1 <= N <= 10^3 
// -10^6 <= TRIANGLE[i][pos] <= 10^6 ,      


// NOTE --> Here, Starting pt fixed hai, Lekin last row me koi bhi ending pt ho skta hai

// GREEDY will not work, Kyuki agar locally min. liya to aage chalke by compulsion max. lena padd skta hai...
// GREEDY tabhi lagao jab PROVE kar sakte ho Logic

// Ex -> [1] [2 3] [100 101 9]

// Try out all Possible paths

// Here, Ending pts. are Variable -> So do recursion in Reverse Striver way i.e 0 -> (n-1) row becz we have fixed st. p

// RECURSION ---------------->>

// STATE -> f(i,j) -> min sum path from (i, j) to last row
// Final Subproblem -> f(0, 0)
// Base case -> f(n-1, j)

// We will never go out of bound, har ek f(i, j) ke liye i+1 row me arr(i+1, j) and arr(i+1, j+1) cell rhnga

// TIME -> O(2 ^ n)
// Space -> O(n)



// OVERLAPPING SUBPROBLEMS ---------------------->>

// Just Draw the Recursion Tree, you will see..


// MEMOIZATION ------------------------------->>>

// -10^6 <= TRIANGLE[i][pos] <= 10^6 

// Then why DELIMETER = -1 , -1 min. cost path hua to ?? 
// Yha pe hume dp[i][j] ki value se consider nhi krna hai min ko, hume sirf cell ke liye uske down and diagonal ka min. lena hai...
// Humko sirf Yeah assure krna hai same cell ek baar se jyada visit na hoye..
// -1 will be not visited and dp[i][j] ek baar value le liya to uss cell ki wahi value hai, usko dobara call pe return kar denga...

#include <bits/stdc++.h>
using namespace std;

int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n, vector<vector<int> > &dp) {

    if (dp[i][j] != -1)  return dp[i][j];

    if (i == n - 1)   return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);

}

int minimumPathSum(vector<vector<int> > &triangle, int n) {

    vector<vector<int> > dp(n, vector<int>(n, -1));    

    return minimumPathSumUtil(0, 0, triangle, n, dp);

}

// TIME -> O(n * n)
// SPACE -> O(n) [stack]  + O(n * n) ( dp array )


// ITERATIVE ---------------------------->>

// Just see the flow of states --> 
// ith row is dependant on i+1 row
// So, we will loop in row as -> n-1 to 0

int minimumPathSum(vector<vector<int> > &triangle, int n) {

    vector<vector<int> > dp(n, vector<int>(n));

    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {

        for (int j = 0; j <= i; j++) {

            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);

        }
    }

    return dp[0][0];

}

// SPACE -> O(n * n)


// SPACE OPTIMIZATION ------------------------->>>

int minimumPathSum(vector<vector<int>> &triangle, int n) {

    vector<int> front(n, 0); // Represents the previous row
    
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    for (int i = n - 2; i >= 0; i--) {

        vector<int> cur(n, 0);   // Represents the current row

        for (int j = 0; j <= i; j++) {

            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            cur[j] = min(down, diagonal);

        }

        front = cur;
    
    }
    
    return front[0];

}

// SPACE -> O(n)

int main() {

    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}
