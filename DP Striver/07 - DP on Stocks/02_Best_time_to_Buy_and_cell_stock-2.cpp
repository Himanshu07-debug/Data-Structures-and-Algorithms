#include<bits/stdc++.h>
using namespace std;

// LOGIC ----------------------------->>

// The mistake you did is that you assume that in this Question , It is mandatory to either buy / sell on each day. 
// But that not the case -> You can even move without buying or selling...

// The line from the Question -  "You can only hold at most one share of the stock at any time".
// At most , means you can also go without a stock.

// In this Question, at any iex i, If you purchased the stock previously, then you can't Purchased it again, you have to sell it first...
// This means I have to keep track of the info - that I purchased the stock previously or not..

// We will keep a parameter -> buy
// buy = 0 --> We had not purchased the stock previously
// buy = 1 --> We had purchased the stock previously


// If purchased at iex i , we will add -arr[i] to the profit ( arr[sell] - arr[buy] , that's why final sum me -arr[buy] )
// If sale at iex i, we will add arr[i] to the profit


// RECURSIVE -->
// Time -> O(2 ^ n)
// SPACE -> O(n)


// MEMOIZATION -->

long getAns(long *arr, int i, int buy, int n, vector<vector<long>> &dp) {

    if (i == n) {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[i][buy] != -1) {
        return dp[i][buy];
    }

    long profit = 0;

    if (buy == 0) { 
        // We can buy the stock

        profit = max(0 + getAns(arr, i + 1, 0, n, dp), -arr[i] + getAns(arr, i + 1, 1, n, dp));
    }

    if (buy == 1) { 
        // We can sell the stock

        profit = max(0 + getAns(arr, i + 1, 1, n, dp), arr[i] + getAns(arr, i + 1, 0, n, dp));
    }

    return dp[i][buy] = profit;

}

long getMaximumProfit(long *arr, int n) {

    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(arr, 0, 0, n, dp);

    return ans;
}

// TABULATION -------------------------->>>

long getMaximumProfit(long *arr, int n) {


    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = 0;
    dp[n][1] = 0;

    long profit;


    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {

            if (buy == 0) { 
                // We can buy the stock
                profit = max(0 + dp[i + 1][0], -arr[i] + dp[i + 1][1]);
            }

            if (buy == 1) { 
                // We can sell the stock
                profit = max(0 + dp[i + 1][1], arr[i] + dp[i + 1][0]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][0];

}


// SPACE ------------------------------>>

long getMaximumProfit(long *arr, int n) {

    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = ahead[1] = 0;

    long profit;


    for (int ind = n - 1; ind >= 0; ind--) {

        for (int buy = 0; buy <= 1; buy++) {

            if (buy == 0) { 
                // We can buy the stock
                profit = max(0 + ahead[0], -arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], arr[ind] + ahead[0]);
            }

            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    return cur[0];
    
}