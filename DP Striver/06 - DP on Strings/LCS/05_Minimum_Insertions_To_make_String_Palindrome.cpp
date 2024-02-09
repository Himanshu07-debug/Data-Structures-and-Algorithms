#include<bits/stdc++.h>
using namespace std;

// We need to find the minimum insertions required to make a string palindrome. Let us keep the “minimum” criteria aside and think, 
// how can we make any given string palindrome by inserting characters?
// The easiest way is to add the reverse of the string at the back of the original string, this will always be a Palindrome.
// "aaba" --> "aabaabaa"
// Here the number of characters inserted will be equal to n (length of the string). This is the maximum number of characters we 
// can insert to make strings palindrome.

// If we know the longest palindromic sub-sequence is x and the length of the string is n then, what is the answer to this problem? 
// It is n - x as we need n - x insertions to make the remaining characters also palindrome.
// Jo characters LPS me nhi hai, unke reverse order ko coresponding indexes pe add kro to make entire string Palindrome.....
// REMEMBER -> There are many Palindrome, But taking the Longest is the OPTIMAL ONE

// The Problem Boils up to LPS and LCS.


int lcs(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}


int longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}


int minInsertion(string s) {
    int n = s.size();
    int k = longestPalindromeSubsequence(s);

    return n - k;
}

// NOTE --> Agar Minimum no. of deletions rhta question me, tab bhi code yhi rhta becz usme thinking yeah rhti ki min. kitne characters ko delete
//          kru to get the Palindromic String.

int main() {
    string s = "abcaa";
    
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion(s);
    return 0;

}



// If It is SAID that --> Do not use extra string..

// Then, at any moment you have 3 choices when s[l] != s[r] 
// Either to make insertion at first / at the last  / At both side 

int minStep(int l, int r, string& s, vector<vector<int>>& dp) {

    if (l > r || l == r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    if (s[l] == s[r]) {
        return dp[l][r] = minStep(l + 1, r - 1, s, dp);
    } else {

        int p1 =
            min(minStep(l + 1, r, s, dp) + 1, minStep(l, r - 1, s, dp) + 1);

        int p2 = 2 + minStep(l + 1, r - 1, s, dp);

        return dp[l][r] = min(p1, p2);
    }
}

int minInsertions(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return minStep(0, n - 1, s, dp);
}
