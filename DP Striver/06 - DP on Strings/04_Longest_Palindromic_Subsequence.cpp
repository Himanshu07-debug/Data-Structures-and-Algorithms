#include<bits/stdc++.h>
using namespace std;

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

    // return longest(0, n-1, s, dp);

    for(int i=n-1;i>=0;i--){

        for(int j=0;j<n;j++){

            if(i > j) dp[i][j] = 0;
            else if(i == j) dp[i][j] = 1;
            else if(s[i] == s[j]){
                if(i + 1 < n && j - 1 >= i) dp[i][j] = 2 + dp[i+1][j-1]; 
            }
            else{
                int p1 = 0, p2 = 0;
                if(i + 1 < n) p1 = dp[i+1][j];
                if(j - 1 >= 0) p2 = dp[i][j-1];

                dp[i][j] = max(p1, p2);
            }

        }

    }

    return dp[0][n-1];
        
}