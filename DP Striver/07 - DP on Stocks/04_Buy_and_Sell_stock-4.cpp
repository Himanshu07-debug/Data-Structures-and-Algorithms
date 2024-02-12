// We are given an array arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// 1. We can buy and sell the stock any number of times.
// 2. In order to sell the stock, we need to first buy it on the same or any previous day.
// 3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
// 4. We can do at-most K transactions.

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4 - 2 = 2.


// LOGIC ----------------------------------->>>

// Same like prev Best_time - 03 question, only here we have capacity of K

// Another way of Solving 2D array

// Total Transaction cnt considering both Selling and Buying --> 2 * K

#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int>& arr, int n, int i, int cap, vector<vector<int>>& dp) {

    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if (i == n || cap == 0)
        return 0;

    if (dp[i][cap] != -1)
        return dp[i][cap];

    int profit;

    if (cap % 2 == 0) { 

        // We can buy the stock
        profit = max(0 + getAns(arr, n, i + 1, cap, dp), -arr[i] + getAns(arr, n, i + 1, cap - 1, dp));

    }

    if (cap % 2 == 1) { 
        
        // We can sell the stock
        profit = max(0 + getAns(arr, n, i + 1, cap, dp), arr[i] + getAns(arr, n, i + 1, cap - 1, dp));
    }

    return dp[i][cap] = profit;

}

int maxProfit(vector<int>& prices, int n, int k) {

    // Creating a 3D DP array of size [n][2][3]
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));

    return getAns(prices, n, 0, 2 * k, dp);

}


// TABULATION ----------------------------------->>

int maxProfit(int k, vector<int>& arr) {

    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(2*k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {

            for (int cap = 1; cap <= 2*k; cap++) {

                if (cap % 2 == 0) { 
                    // We can buy the stock
                    dp[ind][cap] = max(0 + dp[ind + 1][cap], -arr[ind] + dp[ind + 1][cap - 1]);
                }

                if (cap % 2 == 1) { 
                    // We can sell the stock
                    dp[ind][cap] = max(0 + dp[ind + 1][cap], arr[ind] + dp[ind + 1][cap - 1]);
                }
            }

    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][2*k];

}




