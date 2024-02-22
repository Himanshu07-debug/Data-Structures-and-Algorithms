#include <bits/stdc++.h>
using namespace std;


// RECURSION -------------------------------->>

// I am Lazy, I only make all possible first partition by checking the Starting Palindrome Possible, Rest Recursion tum kar dena

// Reference --> Recursion ka Palindrome Partitioning 1

// Memoization ------------------------------------>>>

bool isPalindrome(int i, int j, string &s){

    if(i >= j) return true;

    return (s[i] == s[j]) && isPalindrome(i+1, j-1, s); 

}

int fun(int i, int n, string &s, vector<int> &dp){

    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int mi = INT_MAX;

    for(int j = i; j < n; j++){

        if(isPalindrome(i, j, s)){

            int cut = 1 + fun(j + 1, n, s, dp);

            mi = min(mi, cut);

        }

    }

    dp[i] = mi;

}


int minCut(string s) {
        
    int n = s.size();

    vector<int> dp(n, -1);

    return fun(0, n, s, dp) - 1;

}

// It is O(n ^ 3)
// We can make it O(n^2) by preparing palindrome[i][j] table initially.. Palindrome Substrings Question ka Logic --> O(n^2) me ban jayega

// Now O(1) me check ho jayega , i to j wali string Palindrome hai kya


// TABULATION ------------------------------->>

int minCut(string s) {
        
    int n = s.size();

    vector<int> dp(n + 1, 0);

    for(int i = n-1 ; i >= 0 ; i--){

        int mi = INT_MAX;

        for(int j = i; j < n; j++){

            if(isPalindrome(i, j, s)){

                int cut = 1 + dp[j + 1];

                mi = min(mi, cut);

            }

        }

        dp[i] = mi;

    }

    return dp[0] - 1;

}


