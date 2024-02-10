#include<bits/stdc++.h>
using namespace std;

// LOGIC ----------------------------->>

// The mistake you did is that you assume that in this Question , It is mandatory to either buy / sell on each day. 
// But that not the case -> You can even move without buying or selling...

// The line from the Question -  "You can only hold at most one share of the stock at any time".
// At most , means you can also go without a stock.

// Therefore, Every day, we will have two choices, either to do nothing and move to the next day or to buy/sell. 
// We need to generate all the choices in order to compare the profit. As we need to try out all the possible choices, we will use recursion.

// In this Question, at any indx i, If you purchased the stock previously, then you can't Purchased it again, you have to sell it first...
// This means I have to keep track of the info - that I purchased the stock previously or not..

// We will keep a parameter -> buy
// buy = 0 --> We had not purchased the stock previously
// buy = 1 --> We had purchased the stock previously

// CHOICE 1 -->
// If we buy the stock on the current day. In this case, the net profit earned from the current transaction will be -arr[i]. As we are 
// buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative.

// CHOICE 2 -->
// If we sell the stock on the current day. In this case, the net profit earned from the current transaction will be +arr[i].
// As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive.


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


    for (int i = n - 1; i >= 0; i--) {

        for (int buy = 0; buy <= 1; buy++) {

            if (buy == 0) { 
                // We can buy the stock
                profit = max(0 + ahead[0], -arr[i] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], arr[i] + ahead[0]);
            }

            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    return cur[0];
    
}

// NOTE -> Some Coders use 4 variables instead of curr and ahead vector and not the second loop of 2 . this will Optimize the code very little 
//         bit.


long getMaximumProfit(long *arr, int n) {

    long aheadBuy, aheadNotBuy;
    long currBuy, currNotBuy;

    aheadBuy = aheadNotBuy = 0;

    for (int i = n - 1; i >= 0; i--) {

        currBuy = max(0 + aheadBuy, -arr[i] + aheadNotBuy);

        currNotBuy = max(0 + aheadNotBuy, arr[i] + aheadBuy);


        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;

    }

    return aheadBuy;

}

// GREEDY --------------------------------->>

// Make a Graph, Purchased at low price day and sell it on high price day

