#include <bits/stdc++.h>
using namespace std;

// this is similar to Palindorme Partitioning Problem

// Recursion --->

// We are allowed to make subarray of length atmost k.
// I am lazy, Mai starting ka possible subarray bana dunga <= k size, aage ka Recursion Baba dekh lena

// Memoization --->

int fun(int i, int n, vector<int> &arr, int k, vector<int> &dp){

    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int mx = 0;

    int val = -1;

    for(int j = i; j < n && j < i + k ; j++){        // --> Here this can be reduced to ---> j < min(n, i + k)

        val = max(val, arr[j]);

        int sum = val*(j - i + 1) + fun(j+1, n, arr, k, dp);
        mx = max(mx, sum);

    }

    return dp[i] = mx;

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
    int n = arr.size();

    vector<int> dp(n, -1);

    return fun(0, n, arr, k, dp);

}


// TIME -> O(n * k)
// SPACE -> O(n) + O(n) [ Call stack ]


// TABULATION ------------------------->>

int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
    int n = arr.size();

    vector<int> dp(n + 1, 0);

    for(int i = n-1; i >= 0; i--){

        int mx = 0;

        int val = -1;

        for(int j = i; j < min(n, i + k) ; j++){

            val = max(val, arr[j]);

            int sum = val*(j - i + 1) + dp[j+1];
            mx = max(mx, sum);

        }

        dp[i] = mx;


    }

    return dp[0];

}
