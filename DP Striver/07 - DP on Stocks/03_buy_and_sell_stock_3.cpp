#include<bits/stdc++.h>
using namespace std;

// In part 2, we were allowed to do INFINITE TRANSACTIONS.

// Same like Previous --> Trying out all the Possibility of buying and selling stocks... 
//                        (Isme 0, 1, 2 transaction bhi included hai )

// Here, we have to take 3 parameters , 3rd Parameter ???
// Hum same indx i pe diff states se aa sakte hai i.e ho sakta hai previously 1 transaction complete karke aaye ho or No transaction ke sath, etc

// NOTE : Buying and selling a stock together counts as one complete transaction.



// MEMOIZATION ----------------------------------->>>


int getAns(vector<int>& arr, int n, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {

    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if (i == n || cap == 0)
        return 0;

    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];

    int profit;

    if (buy == 0) { 

        // We can buy the stock
        profit = max(0 + getAns(arr, n, i + 1, 0, cap, dp), -arr[i] + getAns(arr, n, i + 1, 1, cap, dp));

    }

    if (buy == 1) { 
        
        // We can sell the stock
        profit = max(0 + getAns(arr, n, i + 1, 1, cap, dp), arr[i] + getAns(arr, n, i + 1, 0, cap - 1, dp));
    }

    return dp[i][buy][cap] = profit;

}

int maxProfit(vector<int>& prices, int n) {

    // Creating a 3D DP array of size [n][2][3]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return getAns(prices, n, 0, 0, 2, dp);

}


// TABULATION -------------------------------------------->>>

int maxProfit(vector<int>& Arr, int n) {

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.

    for (int ind = n - 1; ind >= 0; ind--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int cap = 1; cap <= 2; cap++) {

                if (buy == 0) { 
                    // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { 
                    // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];

}


// SPACE OPTIMIZATION -------------------------------------------------------->>>>

int maxProfit(vector<int>& Arr, int n) {

    // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {

                if (buy == 0) { 
                    // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap], -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { 
                    // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap], Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }

        ahead = cur;

    }

    return ahead[0][2];
    
}


// SPACE OPTIMIZATION ---------------------->>>

// At most 2 transactions , what this actually means ?
// Observe, We can do max 2 purchase and max 2 sell.... Order ==> B S B S ...
// So agar Hum 4 transaction le, then on Even Transaction (0 , 2) we can sell on Transaction (1, 3) --> Buy parameter ki need nhi
// This is only Space Optimization --> n * 2 * 2 ---> n * 4

// NOTE --> Iska Implementation Buy and sell stock Problem - 4 me

