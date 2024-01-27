// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, 
// return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Constraints:

// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000


// LOGIC ------------------------------------>>

// Pick not pick logic se ho jayega , Same like Minimum_coins 



#include <bits/stdc++.h> 
using namespace std;

int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(T == 0) return 1;

    if(ind == 0){

        if(T % arr[0] == 0)     return 1; 
        else
            return 0; 
    }
    
    if(dp[ind][T] != -1)
        return dp[ind][T];
        
    int notTaken = minimumElementsUtil(arr, ind - 1, T, dp);
    
    int taken = 0; 

    if(arr[ind] <= T)
        taken = minimumElementsUtil(arr, ind, T - arr[ind], dp);
        
    return dp[ind][T] = notTaken + taken;

}


int change(int x, vector<int>& arr) {

    int n = arr.size();

    vector<vector<int>> dp(n , vector<int> (x+1, -1));

    return minimumElementsUtil(arr, n-1, x, dp);
        
}

// I was getting in Error in CN IDE, becz answer was expected in long, I was writing int (though they are same but if long is the return type),
// make Your dp datatype as long, everything as long, only left the Input Parameters datatypes.


// ITERATIVE , SPACE