
#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> arr, int i, int buy, int n, vector<vector<int>> &dp) {

    if (i >= n) return 0;
    
    // Check if the result is already computed
    if (dp[i][buy] != -1)
        return dp[i][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(arr, i + 1, 0, n, dp), -arr[i] + getAns(arr, i + 1, 1, n, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(arr, i + 1, 1, n, dp), arr[i] + getAns(arr, i + 2, 0, n, dp));
    }
    
    // Store the result in the DP array and return
    return dp[i][buy] = profit;
}

int stockProfit(vector<int> &arr) {

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    int ans = getAns(arr, 0, 0, n, dp);
    return ans;
}

// ITERATIVE ----------------------------------------->>

int stockProfit(vector<int> &arr) {

    int n = arr.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}


// SPACE OPTIMIZATION ----------------------->>

int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    
    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> cur(2, 0);       // Current maximum profit
    vector<int> front1(2, 0);    // Maximum profit one step ahead
    vector<int> front2(2, 0);    // Maximum profit two steps ahead
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' arrays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0]; // Return the maximum profit for buying.
}


