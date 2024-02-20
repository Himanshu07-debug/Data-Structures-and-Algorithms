#include<bits/stdc++.h>
using namespace std;

// No matter what is the freq of arr[i], You have to take them all if you select to take arr[i]

// If We sort the elements, we dont have to care about deleting arr[i] + 1 , we only have to care about arr[i] - 1

// Extension to house Robber Problem

// MEMOIZATION ---->

int fun(int i, vector<int> &cnt, vector<int> &dp){

    if(i == 0) return 0;

    if(i == 1) return cnt[i];

    if(dp[i] != -1) return dp[i];

    int pick = cnt[i]*i + fun(i-2, cnt, dp);
    int skip = fun(i-1, cnt, dp);

    return dp[i] = max(pick, skip);

}

int deleteAndEarn(vector<int>& arr) {

    int n = arr.size();

    vector<int> cnt(1e4 + 1, 0);

    int mx = -1;

    for(int i=0;i<n;i++){
        cnt[arr[i]]++;
        mx = max(mx, arr[i]);
    }

    vector<int> dp(mx + 1, -1);

    return fun(mx, cnt, dp);

}