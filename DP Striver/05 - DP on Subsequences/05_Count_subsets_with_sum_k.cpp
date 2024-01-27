// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

// Input: 'arr' = [1, 1, 4, 5]
// Output: 3 ( [1, 4] , [1, 4] , [5])

// Constraint -> 
// 1 <= 'n' <= 100
// 0 <= 'arr[i]' <= 1000
// 1 <= 'k' <= 1000


// REMEMBER ,
// Striver ka code will give wrong answer in case of Counting if array contains 0
// WHY ? 
// Apan (ind == 0) pe (arr[ind] == target) check kar rhe hai... If yes, then return 1 krnge, otherwise 0
// But if target == 0 hai and arr[0] = 0, then 0 pick kro yaa na kro, target 0 hi rhnga i.e 2 subsets are possible....
// So we have to handle this..
// Also if target == 0 ho gya to hum return kar rhe hai, kya malum uss subset ke piche bhi 0 hai, to unse bhi subset banege current wale ke, uska
// cnt consider nhi ho payega....


// Abhi tk Problem nhi aayi ?? 
// We were Checking till now, not counting ...

// NOTE -> When 0 <= arr[i] i.e array me 0's allowed, You have to handle this in case of Cnt Q.s..

// APPROACH -->

// Hum beech me target == 0 aaya to return nhi kar sakte, we have to go deeper and deeper in the subset i.e ind = 0 tk jayenge....

// We will create all subsets till indx 1 , jab indx == 0 ki baari aayeangi, Base case, hum diff cases me respective values return kar denge...


// Ex -> {0 , 0, 1} , target -> 1   , arr[0] = 0
// Subsets till indx 1 -> {0, 1} , {1} , {0}
// Now, {0, 1} me target == 1 hai, uske subset me 0 add kiya to no effect, so 2 subsets possible
// {1} me bhi 2, ho gya


// Memoization --------------------->>

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


int findWays(vector<int>& arr, int k)
{
	// Write your code here.

	int n = arr.size();

	vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);

}


// ITERATIVE ------------------------>>>

int subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Just apply the Recursion Base case Logic here
    // NOTE -> In Interview, You have to Explain from the Memoization code only, that this will be our Base case

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

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];

}

// SPACE -------------------->.

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





