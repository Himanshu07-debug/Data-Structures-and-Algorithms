#include <bits/stdc++.h>
using namespace std;

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// We have to match s1 to s2 ...

// We will proceed with our String Matching Intuition only...

// Cases -->

// If s1[i] == s2[j] 
// They match --> Move ( i - 1,  j - 1)


// If s2[j] == '?'
// We can explicitly match ‘?’ at index j of s2 with the corresponding character at index i of s1. And then recursively call f(i-1,j-1) 
// to check for the remaining string.

// If s2[j] == '*'
// This is an IMP case --> We can't predict upto how much length of sequence of characters we should take ... 

// For Example --> s1 = "abdabgcd"  , s2 = "ab*cd"
// Hum "cd" cover kar denge --> Now when at * , s1 ke konse b tak sequence le, we cant Decide... Agar phle b pe ruk gye to Wrong, jabki true hai
// answer
// For loop se kar sakte ho ki jab-jab b milega, aap next call kronge uss ith index. But this is not the Smart Way..
// We are maintaining 2 pointers in our Code, we can take advantage from them...

// Therefore, In such type of cases, Instead of Thinking for FOR loop, try out all sequences by * aur agar ek bhi True de diya, Ho gya
// This means , we will stop if we check one b, we will move increase our sequence to check for further "b"

// 1. Call f(i,j - 1). i.e replace ‘*’ with nothing (empty sequence) and act as if it was not present.

// 2. Call f(i - 1, j). i.e replace ‘*’ with a single character at index i and make the j pointer to still point at index j. 
// In this, we matched it with a single character (one of the many options that need to be tried) and in the next recursive call, 
// as j still point to ‘*’, we get the exact two recursive calls again.


// LAST CASE --> If s1[i] != s2[j]  --> Return false (no way they can be equal (different characters))


// BASE CASE ---->

// if i < 0 && j < 0  ---> Return true
 
// If s2 gets exhausted and s1 not --> Return false

// If s1 gets exhausted and s2 not ---> 
// Here can be a Case, s1 = "" can be equal to the s2 filled with all stars from [0 .. j] , so check for this case


// MEMOIZATION ------------------------------>>


bool match(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

    if(i < 0 && j < 0) return true;

    if(i >= 0 && j < 0)  return false;

    if(i < 0 && j >= 0){

        while(j >= 0 && s2[j] == '*') j--;

        if(j < 0) return true;
        else return false;

    }

    if(dp[i][j] != -1) return dp[i][j]; 

    if(s1[i] == s2[j] || s2[j] == '?' ){
        return dp[i][j] = match(i-1, j-1, s1, s2, dp);
    }
    else{

        if(s2[j] == '*'){
            bool p1 = match(i, j-1, s1, s2, dp);
            bool p2 = match(i-1, j, s1, s2, dp);

            return dp[i][j] = p1 | p2;
        }
        else return dp[i][j] = false;

    }

}

bool isMatch(string s, string p) {

    int n = s.size() , m = p.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return match(n-1, m-1, s, p, dp);
        
}

// SPACE -> O(n * m) + O(n + m)




// Tabulation ---->

bool isMatch(string s1, string s2) {

    int n = s1.size() , m = s2.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    for(int i=1;i<=n;i++){
        dp[i][0] = false;
    }

    for(int j=1;j<=m;j++){
        
        if(s2[j-1] != '*')  break;

        dp[0][j] = true; 

    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(s1[i-1] == s2[j-1] || s2[j-1] == '?' ){
                dp[i][j] = dp[i-1][j-1];
            }
            else{

                if(s2[j-1] == '*'){
                    bool p1 = dp[i][j-1];
                    bool p2 = dp[i-1][j];

                    dp[i][j] = p1 | p2;
                }
                else{
                    dp[i][j] = false;
                }

            }

        }

    }

    return dp[n][m];
        
}


// SPACE --------------------------------->>

bool isMatch(string s1, string s2) {

    int n = s1.size() , m = s2.size();

    vector<bool> prev(m+1, false) , curr(m+1, false);

    prev[0] = true;

    for(int j=1;j<=m;j++){
        
        if(s2[j-1] != '*')  break;

        prev[j] = true; 

    }

    for(int i=1;i<=n;i++){

        curr[0] = false;

        for(int j=1;j<=m;j++){

            if(s1[i-1] == s2[j-1] || s2[j-1] == '?' ){
                curr[j] = prev[j-1];
            }
            else{

                if(s2[j-1] == '*'){
                    bool p1 = curr[j-1];
                    bool p2 = prev[j];

                    curr[j] = p1 || p2;
                }
                else{
                    curr[j] = false;
                }

            }

        }

        prev = curr;

    }

    return prev[m];
        
}