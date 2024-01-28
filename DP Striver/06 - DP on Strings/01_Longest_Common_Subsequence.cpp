// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without 
// changing the relative order of the remaining characters.

// s1 = "ace" , s2 = "abcdef"  ---> LCS -> "ace"

// 1 <= S1.length, S2.length <= 1000

// LOGIC ------------------------------------------>>

// Brute -> Generate All possible subsets of both string and check for the common one from both of them subsets array. 
//          Exponential time Complexity


// RECURSION Another way ->

// Generate all possible subsequences and Compare on the way...

// NOTE -> 
// 1. In Array, you were doing pick - skip logic . In String, You will do Match - Not Match

// Like in array, you use index parameters, In string also, this will be the same...
// Here, we have two String, So two index parameters.

// Do comparisons Character wise..

// At any moment, there will be 2 cases ->
// s1[i] == s2[j] --> Take this Character and call f(i-1, j-1)
// s1[i] != s2[j] --> max( f(i - 1, j) , f(i, j - 1) )   

// Eg For 2nd case -> s1 = ec , s2 = ce .. How you will compare similar ones in both string agar dono ke indx ko -1 kar diye


// RECURSION TIME -> O(2^n) * O(2^m) [ We are considering out all possibilities of both strings ]


// RECURSION TREE --> There are many Overlapping Subproblems. 

// MEMOIZATION --------------->>

// STATE -> f(i, j) -> LCS of a s1[0 .. i] & s2 [0 .. j]

// TIME -> O(n * m)
// SPACE -> O(n * m) + O(n + m) [ AB / CD  -> Draw Recursive Tree. Alternative deletions are happening here in a Longest path. B -> D -> A -> C ]
// For O(n + m) -> See Photo
// We are using an auxiliary recursion stack space O(N + M) (see the recursive tree, in the worst case, we will go till N + M calls at a time)


#include <bits/stdc++.h>
using namespace std;

int LCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

    if( i < 0 || j < 0 ) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) dp[i][j] = 1 + LCS(i-1, j-1, s1, s2, dp);
    else{
        dp[i][j] = max(LCS(i-1, j, s1, s2, dp) , LCS(i, j-1, s1, s2, dp));
    }

    return dp[i][j];

}

int longestCommonSubsequence(string s1, string s2) {

    int n = s1.size() , m = s2.size();

    vector<vector<int>> dp(n, vector<int> (m , -1) );

    return LCS(n-1, m-1, s1, s2, dp);
    
}

// ITERATIVE --------------------->>

// BASE CASE -> i < 0 && j < 0 
// isko kaise handle kronge. Negative index nhi le sakte.

// We will do shifting of index. We will assume 1 based indexing for Strings and n+1, m+1 size ka banaenge. First row/col --> 0

// TIME -> O(n * m)
// SPACE -> O(n * m)


int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 


    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }


    for (int ind1 = 1; ind1 <= n; ind1++) {

        for (int ind2 = 1; ind2 <= m; ind2++) {

            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }

    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence

}


// SPACE -------------------------------------------------->>>

int lcs(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++) {

        for (int ind2 = 1; ind2 <= m; ind2++) {

            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }

        prev = cur; // Update the previous row with the current row

    }

    return prev[m]; // Return the length of the Longest Common Subsequence

}


