#include<bits/stdc++.h>
using namespace std;

// Memoization --------------------->>>

int ways(int i, int n, string &s, vector<int> &dp){

    if(i == n) return 1;

    if(s[i] == '0') return 0;

    if(dp[i] != -1) return dp[i];

    int x = ways(i+1, n, s, dp);

    int y = 0;

    if(i + 1 < n){

        int num = (s[i] - '0')*10 + (s[i+1] - '0');

        if(num <= 26){
            y = ways(i+2, n, s, dp);
        }

    }

    return dp[i] = x + y;

}

int numDecodings(string s) {

    int n = s.size();

    vector<int> dp(n, -1);

    return ways(0, n, s, dp);

}


// Iterative --------------------->>


int numDecodings(string s) {

    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[n] = 1;

    for(int i=n-1;i >= 0;i--){

        if(s[i] == '0') continue;

        int x = dp[i+1];

        int y = 0;

        if(i + 1 < n){

            int num = (s[i] - '0')*10 + (s[i+1] - '0');

            if(num <= 26){
                y = dp[i+2];
            }

        }

        dp[i] = x + y;

    }

    return dp[0];

}


// SPACE --->

int numDecodings(string s) {

    int n = s.size();

    int p1 = 1, p2 = 0;

    for(int i=n-1;i >= 0;i--){

        if(s[i] == '0'){
            p2 = p1;
            p1 = 0;
            continue;
        }

        int x = p1;

        int y = 0;

        if(i + 1 < n){

            int num = (s[i] - '0')*10 + (s[i+1] - '0');

            if(num <= 26){
                y = p2;
            }

        }

        p2 = p1;

        p1 = x + y;

    }

    return p1;

}
