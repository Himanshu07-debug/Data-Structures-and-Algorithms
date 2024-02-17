// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all 
// the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


// LOGIC -------------------------->>

// We can try out all Possibilties i.e ek baar sum - arr[i] and ek baar sum + arr[i] krnge last indx tk and then jo sum == target rhnga, wo
// Valid Arrangement honga...

// But did you get this, This will not be most Efficient...
// Target can be -ve, dp ??, map use kronge, usase bhi Time increase honga....

// NOTE -> This Companies gives You the Same Previous logic Question, only they change the Question language so that you find it as a new Problem..
//         If You can Link the Problem with some Previous Pattern / Problem, You are Done...

// Previously, we had done ->
// 1. Count of Subsets with sum equal to K
// 2. Count Partitions with Given diff ( S1 - S2 == D )

// Yha pe arrangement me Some +ve no.s honge and Some -ve honge... -ve numbers se - bahar nikal lu to.. 
// S1 - S2 = target ( S1 => +ve numbers set ,, S2 => -ve numbers set )

// Now, given Problem reduce to a Problem that we had done Previously...

// Here, S1 and S2 both +ve honge .. 

// So count the number of Subsets with sum S2 = (totsum - target)/2

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

int targetSum(int n, int k, vector<int>& arr) {
    
    return countPartitions(n, k, arr);

}

// Iterative , Space -> You can do..

// NOTE -> this is DSA and its Intuition... Apko Hamesha apne Past knowledge ko puchna honga.. Patters Figure out krne honge



