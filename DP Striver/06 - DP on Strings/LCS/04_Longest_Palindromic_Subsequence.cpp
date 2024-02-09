#include<bits/stdc++.h>
using namespace std;

// NAIVE -------------------------->>

// Genearting all possible subsets, Storing them in an vector, and then checking for Longest Palindromic Subsequence

// Memoization ------------------------------->>>

// Tactics -->
// 1. Palindrome Checking in Recursion.. 
// 2. If s[l] != s[r] --> LCS logic to call all combinations of Subsequences and taking max of them


// Approach 2 --> 
// Agar String Palindrome hai to --> 
// What is special about this Palindromic string is that it is equal to its reverse.

// So we can take one more string i.e Reverse(str) and then 2 string ho gyi, Find longest LCS in both of them

// We have taken the reverse of the string for the following two reasons:

// 1. The longest palindromic subsequence being a palindrome will remain the same when the entire string is reversed.
// 2. The length of the palindromic subsequence will also remain the same when the entire string is reversed.

// From the above discussion we can conclude:
// The longest palindromic subsequence of a string is the longest common subsequence of the given string and its reverse.


// Appraoch 2 is the Striver One and hence it is recommended. If Interviewer say dont use that extra string, use Appraoch 1.
// Approach 2 profit is that You can Print LCS


// Approach 2 same as LCS hai, Aap kar longe Naive, Better Best

// Appraoch 1 Code


int longest(int l, int r, string &s, vector<vector<int>> &dp){

    if(l == r) return 1;

    if(l > r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    if(s[l] == s[r]){
        dp[l][r] = 2 + longest(l+1, r-1, s, dp);
    }
    else{
        dp[l][r] = max(longest(l+1, r, s, dp), longest(l, r-1, s, dp));
    }

    return dp[l][r];

}

int longestPalindromeSubseq(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    return longest(0, n-1, s, dp);

}

// Iterative ---->>

int longestPalindromeSubseq(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    return longest(0, n-1, s, dp);

    for(int i=n-1;i>=0;i--){

        dp[i][i] = 1;

        for(int j = i+1; j<n;j++){

            if(s[i] == s[j]){
                if(i + 1 < n) dp[i][j] = 2 + dp[i+1][j-1]; 
            }
            else{
                int p1 = 0, p2 = 0;
                if(i + 1 < n) p1 = dp[i+1][j];
                if(j - 1 >= 0) p2 = dp[i][j-1];             // We can skip j-1 as this j-1 will always be >= 0

                dp[i][j] = max(p1, p2);
            }

        }

    }

    return dp[0][n-1];
        
}

// if(i > j) dp[i][j] = 0;
// else if(i == j) dp[i][j] = 1;
// Instead of considering this 2 conditions of base case, I will start second loop from j = i + 1


// SPACE OPTIMIZED YOU CAN DO...