#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Input: s = "rabbbit", t = "rabbit"
// Output: 3

// LOGIC --------------------------------------------->>

// When s1[i] != s2[j] --> Go (i - 1, j)

// When s1[i] == s2[j] --> 
// We have 2 choices -> either to consider this s1[i] in our subsequence and do j-1 or skip it so that further other same value can be considered
// in our Subsequence i.e Keeping the jth index same and i-1

// BASE CASE --->
// if j < 0, it means we have matched all characters of S2 with characters of S1, so we return 1.
// if i < 0, it means we have checked all characters of S1 but we are not able to match all characters of S2, therefore we return 0.

// s1 = "bgg" , s2 = "bg"
// i = 2, j = 1 
// s1[i] == s2[j] --> If you do only j-1, then you reject the second possibility i.e "g" at indx 1 of s1 --> 2 choices


// RECURSIVE -->
// TIME -> O(2^n)
// Space -> O(n) [ n -> length of s1 ]


// MEMOIZATION ------------------------------------>>

const int prime = 1e9 + 7;

int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {

    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;
    
    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;


    if (dp[ind1][ind2] != -1)   return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {

        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;

    } else {

        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);

    }


    dp[ind1][ind2] = result;

    return result;
}

int numDistinct(string s, string t) {

    int n = s.size() , m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return countUtil(s, t, n-1, m-1, dp);
        
}

// TIME -> O(n * m)
// SPACE -> O(n) + O(n * m)


// ITERATIVE --->

// We have Base cases of -ve indexes...
// So Follow our Previous technique ----> Shifting of Indexes

int subsequenceCounting(string &s1, string &s2, int n, int m) {

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // For any i, j == 0 , return 1
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Start j from 1 at row 0 to make them 0
    // We can skip this all cells are already intialized by 0
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } 
            else {
                dp[i][j] = dp[i - 1][j];
            }

        }
    }

    return dp[n][m];
}


// SPACE OPTIMIZATION ---> 

// 2 array

// 1D Array Optimization ==> Knapsack jaise hai State --> You can use Single array with reverse 2nd loop  

int subsequenceCounting(string &s1, string &s2, int n, int m) {

    vector<int> prev(m + 1, 0);

    prev[0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = m; j >= 1; j--) { 
            
            if (s1[i - 1] == s2[j - 1]) {
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as it is
        }
    }

    return prev[m];
}