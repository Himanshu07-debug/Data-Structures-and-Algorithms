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

// Without Palindrome Table --> O(n) Space

int minCut(string s) {

    int n = s.size();

    vector<int> cut(n+1, 0);  // number of cuts for the first k characters

    for (int i = 0; i <= n; i++) cut[i] = i-1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
            cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j]);

        for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
            cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j+1]);
        
    }
    
    return cut[n];
    
}

// Explanation --->

// The definition of 'cut' array is the minimum number of cuts of a sub string. More specifically, cut[n] stores the cut number of 
// string s[0, n-1].

// cut[i] = min. no of cuts of the Substring s[0, i - 1]

// Here is the basic idea of the solution:

// Initialize the 'cut' array: For a string with n characters s[0, n-1], it needs at most n-1 cut. Therefore, the 'cut' array is initialized 
// as cut[i] = i-1

// Use two variables in two loops to represent a palindrome:
// The external loop variable 'i' represents the center of the palindrome. The internal loop variable 'j' represents the 'radius' of 
// the palindrome. Apparently, j <= i is a must.
// This palindrome can then be represented as s[i-j, i+j]. If this string is indeed a palindrome, then one possible value
// of cut[i+j] is cut[i-j] + 1, where cut[i-j] corresponds to s[0, i-j-1] and 1 correspond to the palindrome s[i-j, i+j];

// When the loops finish, you'll get the answer at cut[s.length]


