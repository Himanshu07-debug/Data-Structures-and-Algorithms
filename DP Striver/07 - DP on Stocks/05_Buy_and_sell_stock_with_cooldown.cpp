#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int> &arr, int i, int buy, int n, vector<vector<int>> &dp) {

    if (i >= n) {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[i][buy] != -1) {
        return dp[i][buy];
    }

    int profit = 0;

    if (buy == 0) { 
        // We can buy the stock

        profit = max(0 + getAns(arr, i + 1, 0, n, dp), -arr[i] + getAns(arr, i + 1, 1, n, dp));
    }

    if (buy == 1) { 
        // We can sell the stock

        profit = max(0 + getAns(arr, i + 1, 1, n, dp), arr[i] + getAns(arr, i + 2, 0, n, dp));
    }

    return dp[i][buy] = profit;

}


int maxProfit(vector<int>& arr) {

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return getAns(arr, 0, 0, n, dp);
        
}