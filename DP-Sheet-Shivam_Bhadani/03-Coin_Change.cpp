// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the 
// coins, return -1. You may assume that you have an infinite number of each kind of coin.

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2^31 - 1
// 0 <= amount <= 10^4




// STATE ---> dp[i] -> min. no of coins required to make amount i

// TRANSITION -->
// dp[i] = min( dp[ i - arr[k] ] ) + 1  .. where 0 <= k <= n-1


// Smallest Subproblem --> dp[0] = 0

// Final Subproblem -> dp[x]


// NOTE --> Space Optimization Not possible



#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& arr, int x) {

    int n = arr.size();

    vector<int> dp(x+1,1e9);

    

    dp[0] = 0;

    for(int i=1;i<=x;i++){

        for(int j=0;j<n;j++){

            if(i - arr[j] >= 0){
                dp[i] = min(dp[i],dp[i-arr[j]] + 1);
            }

        }

    }

    return dp[x] == 1e9 ? -1 : dp[x];
        
}