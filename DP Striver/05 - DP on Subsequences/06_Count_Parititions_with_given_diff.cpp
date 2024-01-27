// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements 
// of these two subsets be ‘S1’ and ‘S2’.
// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between 
// ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If N = 4, D = 3, ARR = {5, 2, 5, 1}
// Partition 1: {5, 2, 1}, {5} 
// Partition 2: {5, 2, 1}, {5}
// Therefore 2 partitions...


// Constraint -> 0 <= D <= 2500 ,  1 <= n <= 50 ,  0 <= arr[i] <= 50


// LOGIC -------------------------->>

// Looking Tuff, kya aap relate kar sakte ho koi previous pattern se ???
// Humne aaisa Q.s kiye hai i.e Partition wla, lekin usme single value i.e min nikalna tha, not number of subsets possible...

// We have to find -> 
// S1 - S2 ==> D
// Total_sum = S1 + S2
// ( Total_sum - S2 ) - S2 ==> D
// 2 * S2 ==> Total_sum - D
// Therefore, S2 ==> ( Total_sum - D ) / 2

// Now, this become simple, We have to find out the Count of subarrays with sum equal to ( Total_sum - D ) / 2

// NOTICE -> How we convert a Unknown TDS problem to a Problem that we already know.... this are called as Previous Patterns and Intuition

// Some Edge Cases for our Intuition -->
// arr[i] will be positive integers, So ( Total_sum - D ) >= 0
// Also, all allowed numbers are integers, so the Sum should be in Integer, Not fraction --> So ( Total_sum - D ) % 2 == 0


// MEMOIZATION ---------------------------------->>>

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

int subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // If we have reached the first element in 'arr'
    if (ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
        else if(target == 0 || target == arr[0]) return 1;
        else return 0;
    }


    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];


    int notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);


    return dp[ind][target] = (notTaken + taken) % MOD;

}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;

    for(int x : arr) sum += x;

    if(sum - d < 0 || (sum - d) % 2) return 0;

    int target = (sum - d)/2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return subsetSumUtil(n-1, target , arr, dp);

}


// ITERATIVE --------------------------------->>>

int subsetSumUtil(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if(arr[0] == 0) dp[0][0] = 2;   // target == 0 && arr[0] == 0
    else dp[0][0] = 1;              // target == 0 && arr[0] != 0

    if(arr[0] != 0 && arr[0] <= k)  dp[0][arr[0]] = 1;     // target == arr[0]

    for (int ind = 1; ind < n; ind++) {

        for (int target = 0; target <= k; target++) {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = (notTaken + taken) % MOD;

        }
    }

    return dp[n - 1][k];

}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;

    for(int x : arr) sum += x;

    if(sum - d < 0 || (sum - d) % 2) return 0;

    int target = (sum - d)/2;

    return subsetSumUtil(n, target, arr);

}


// SPACE -------------------->

int spaceOptimization(vector<int>& arr, int n, int target)
{
    vector<int> prev(target+1), curr(target+1);

    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= target)  prev[arr[0]] = 1;


    for(int i=1; i< n; i++)
    {
        for(int j=0; j<= target; j++)
        {
            int left = prev[j];
            int right = 0;

            if(arr[i] <= j) {
                right = prev[j-arr[i]];
            }

            curr[j] = left + right;
        }

        prev = curr;

    }

    return prev[target];

}



