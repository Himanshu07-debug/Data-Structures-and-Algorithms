// You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the
// sum of elements in both subsets is equal.
// For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
// Follow Up: Can you solve this using not more than O(S) extra space, where S is the sum of all elements of the given array?

// LOGIC ---------------------------------------------->>

// If sum(arr) % 2 ==> Then only it is possible to split array into two subsets of equal sum..
// Equal sum will be sum / 2

// So, if agar merko ek subset sum/2 ka mil jaata hai, Then Dusre Subset ka sum by default sum/2 honga (remaining sum)

// So, we have to only check for a subset with sum/2 


#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    if (target == 0)
        return true;

    if(ind == 0){
        return (arr[0] == target);
    }
    
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;

    if(arr[ind] <= target){
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = notTaken || taken;

}

bool canPartition(int n, vector<int>& arr) {

    int totSum = 0;

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)    return false;

    int k = totSum / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);


}

// TIME -> O(n * k) + O(n) [loop for sum]

// SPACE -> O(n) + O(n * k)


// You can change the SubsetSum function to Iterative , Space Optimization
