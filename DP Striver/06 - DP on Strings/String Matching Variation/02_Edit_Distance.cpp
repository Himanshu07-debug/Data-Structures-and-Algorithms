#include <bits/stdc++.h>
using namespace std;

// LOGIC -------------------------------------->>

// If s1[i] == s2[j]  ==>  (i - 1, j - 1)
// If this is true, now as the characters at i and j match, we would not want to do any operations to make them match, so we will just 
// decrement both i and j by 1 and recursively find the answer for the remaining string portion.

// But if s1[i] != s2[j] ==>
// Here we have 3 choices -> Insert, Replace or Delete
// We have to just assume that we had done this operation and make the Correct Recursive Call

// INSERT -> (i , j - 1)
// Adding a character equal to s2[j] -> So jth indx match --> j-1 but not i-1 becz ith indx was not matched.. Inserted one was matched

// DELETE -> (i-1, j)
// Deleting the ith indx i.e j remains at its original index and we decrement i by 1. We perform 1 operation, 
// therefore we will recursively call 1 + f( i-1 , j)

// REPLACE -> (i - 1, j - 1)
// Replaced the s1[i] with s2[j] ==> we have matched both the characters, therefore we decrement both i and j by 1. As the number of operations 
// performed is 1, we will return 1 + f( i-1, j-1)

// BASE CASE -->
// if(j < 0) --> This means Complete s2 string get matched -> We have to remove the remaining i+1 (1-based indexing) characters of s1
// if(i < 0) --> This means s1 string is Exhausted -> Therefore we have to insert j + 1 characters of s2 in s1

// RECURSION -->
// TIME --> O(3 ^(n + m))
// SPACE --> O(n + m)  ---> [(i , j - 1) & (i - 1, j) --> Same like LCS, Therefore (n + m) height]

// MEMOIZATION --->

int count(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){


    if(j < 0) return i+1;

    if(i < 0) return j+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = count(i-1, j-1, s1, s2, dp);
    }
    else{

        int insert = count(i, j-1, s1, s2, dp) + 1;
        int remove = count(i-1, j, s1, s2, dp) + 1;
        int replace = count(i-1, j-1, s1, s2, dp) + 1;

        return dp[i][j] = min(insert, min(remove, replace));

    }

}

int minDistance(string s1, string s2) {

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    return count(n-1, m-1, s1, s2, dp);
        
}


// ITERATIVE ---------------> 

// In the recursive logic, we set the base case too if(i < 0) and if(j < 0) but we can’t set the dp array’s index to -1. 
// Therefore a hack for this issue is to shift every index by 1 towards the right.

int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[n][m];
}

// SPACE OPTIMIZATION ---------------------------->>

// No 1D array Optimization as Our current state is dependant on the Previous states of the current row

int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();


    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    // Initialize the first row
    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++) {

        cur[0] = i; // Initialize the first column of the current row

        for (int j = 1; j <= m; j++) {

            if (S1[i - 1] == S2[j - 1]) {
                cur[j] = prev[j - 1];
            } 
            else {
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; 
    }

    return cur[m];

}
