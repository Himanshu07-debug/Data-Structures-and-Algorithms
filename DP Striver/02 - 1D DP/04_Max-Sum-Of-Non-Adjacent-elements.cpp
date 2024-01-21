// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that 
// no two elements are adjacent in the given arraylist.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// LOGIC -------------------------->>

// At any element, we have only 2 choices, either to pick it in our sum and call (i - 2) or Skip it and call (i - 1)

#include <bits/stdc++.h> 
using namespace std;

// Memoization ----------------------->>>

int fun(int i, vector<int> &arr, vector<int> &dp){

    if(i < 0) return 0;

    if(i == 0) return arr[i];

    if(dp[i] != -1) return dp[i];

    int pick = arr[i] + fun(i-2, arr, dp);
    int skip = fun(i-1, arr, dp);

    return dp[i] = max(pick, skip);

}


// Tabulation ----------------------------------------------->>>>


int solveUtil(int n, vector<int>& arr) {

    vector<int> dp(n, 0);

    // Base case: If there are no elements in the array, return 0
    dp[0] = arr[0];
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {

        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])

        int pick = arr[i];
        if (i > 1) pick += dp[i - 2];

        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        dp[i] = max(pick, nonPick);

    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];

}


// SPACE OPTIMIZATION ---------------------------------------------------------->>>

// Each state depends on the values of exact two previous state... 

int solve(int n, vector<int>& arr) {

    int prev = arr[0];   // Initialize dp[i-1]
    int prev2 = 0;       // Initialize dp[i-2]
    
    for (int i = 1; i < n; i++) {

        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element

        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element

    }
    
    return prev;  // Return the maximum sum

}


int maximumNonAdjacentSum(vector<int> &arr){
    // Write your code here.

    int n = arr.size();

    vector<int> dp(n, -1);

    return fun(n-1, arr, dp);

}