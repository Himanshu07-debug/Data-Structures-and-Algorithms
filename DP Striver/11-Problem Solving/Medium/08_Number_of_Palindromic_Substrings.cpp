#include <bits/stdc++.h>
using namespace std;    

// By LCS, you can only Proposed 2 logics -> 
// Iterative and Space Optimized.
// Also it can be used to Print and Find the Longest length, not for Finding the Number of Substrings

// This is the Best one for Interview -->

// Recursion  -->

bool isPalindrome(string s, int i, int j){

    if(i >= j) return true;

    return (s[i] == s[j]) && isPalindrome(s, i+1, j-1);

}

int countSubstrings(string s) {

    int n = s.size();

    int cnt = 0;

    for(int i=0;i<n;i++){

        for(int j=i+1; j<n ; j++){

            if(isPalindrome(s, i, j)){
                cnt++;
            }

        }

    }

    return cnt;

}

// O(n ^ 3)


// Memoization ---->

bool isPalindrome(string s, int i, int j, vector<vector<int>> &dp){

    if(i >= j) return true;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] != s[j]) return dp[i][j] = false;

    return dp[i][j] = isPalindrome(s, i+1, j-1, dp);

}

int countSubstrings(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));

    int cnt = 0;

    for(int i=0;i<n;i++){

        for(int j=i+1; j<n ; j++){

            if(isPalindrome(s, i, j, dp)){
                cnt++;
            }

        }

    }

    return cnt;

}

// In total, Only n^2 {i , j} pairs will be calculated , kyuki utne hi i, j possible hai.
// Agar Again compute honge to O(1) me return ho jayega

// TIME -> O(n ^ 2)
// Space -> O(n ^ 2)


int countSubstrings(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, 0));

    int cnt = 0;

    for(int i=0;i<n;i++){

        for(int j=i+1; j<n ; j++){

            if(isPalindrome(s, i, j, dp)){
                cnt++;
            }

        }

    }

    return cnt;

}


// ITERATIVE ------------------------>>

// Base case ki 2 situation ho skti hai..
// i == j --> True ( odd length palindrome )
// i > j (adjacent wale same) --> True (even length Palindrome)

// We have to handle both of it...
// For i == j, 1st base case will be handled...
// For i > j --> This means ek state back i and j adjecent the and s[i] == s[j] hua hai i + 1 > j - 1 ho gya
// Therefore for Adjacent --> When (i == j - 1 || j == i + 1) and s[i] == s[j] --> dp[i][j] = true
   
int countSubstrings(string s) {

    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, 0));

    int cnt = 0;

    for(int i=n-1;i>=0;i--){

        for(int j = i ;j < n ;j++){

            // Base case - 1
            if(i == j) dp[i][j] = 1;
            
            // Base case 2
            else if(j == i + 1 && s[i] == s[j]) dp[i][j] = 1;

            else{

                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];

            }

            cnt += dp[i][j];

        }

    }

    return cnt;

}


// SPACE OPTIMIZATION is Possible --> curr and prev


// 2 pointer Approach --->

// Till now, we were Shrinking i and j
// So Rather than shrinking, Lets Expand from Center ...

// 2 types of Expansion Possible ---> 
// for Even length Palindrome --> take center as (i , j)  --> pair of middle one
// for odd length Palindrome --> Take center as (i , i)  --> Single middle one

int palindromeCount(string &s, int i, int j){

    int cnt = 0;

    while(i >= 0 && j < s.size() && s[i] == s[j]){
        i--;
        j++;
        cnt++;
    }

    return cnt;

}

int countSubstrings(string s) {

    int n = s.size();

    int cnt = 0;

    for(int i=0;i<n;i++){

        int even = palindromeCount(s, i, i+1);
        int odd = palindromeCount(s, i, i);

        cnt += (even + odd);

    }

}

// Time --> O(n ^ 2) 
// Space --> O(1)




// Manacher Algo is also Possible  --> O(n) time




