// We are given an array ‘ARR’ with N positive integers. We need to partition the array into two subsets such that the absolute difference 
// of the sum of elements of the subsets is minimum.

// We need to return only the minimum absolute difference of the sum of elements of the two partitions.

// Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].
// Ouput: 1     {3, 1, 5} and {2, 8}. 

// CONSTRAINT --------------------------->>

// 1 <= 'n' <= 10^3
// 0 <= 'arr'[i] <= 10^3
// 0 <= 𝚺 'arr'[i] <= 10^4,  where 𝚺 'arr'[i] denotes the sum of all elements in 'arr'.


// LOGIC ----------------------------------------------->>

// Humko min. absolute diff chahiye.. 
// Subset sum will range from [0 , sum(arr)]

// Hum Check kar sakte hai iss range me one by one that ki particular target sum ka subset hai kya...
// Usme se jo sabse min_difference denga remaining sum ke sath wo answer.....

// Checking subset sum equal to K wle code se ho jayegi

// sum(arr) <= 10^4
// n <= 10^3

// n * sum(arr) = 10^7  <= 10^8 operations

// NOTE -> Humko lekin yeah TLE de rha tha last test case, we had optimized it... 
//         Humko pure range ke sum ke liye check krne ki need nhi.. sum(arr)/2 tk min. diff mil jayega ... abs diff valley jaisa ban rha hai


// MEMOIZATION --------------------------->>


#include <bits/stdc++.h>
using namespace std;

// Function to solve the subset sum problem with memoization
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // If array size is 1, then dp[] will not updated at down, isliye base case pe update

    if (target == 0)
        return dp[ind][target] = true;

    if(ind == 0){
        return dp[ind][target] = (arr[0] == target);      
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

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.

	int s = 0;

	for(int x : arr) s += x;

	int k = s/2;

	vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    for(int i=0;i<=k;i++){

        bool d = subsetSumUtil(n-1, i, arr, dp);

    }

	int mi = INT_MAX;

	for(int i=0; i <= k; i++){
		if(dp[n-1][i] == true){
			int rem = s - i;
			mi = min(mi, abs(rem - i));
		}
	}

	return mi;

}
// TIME -> O(n * k) + O(k) + O(n)
// SPACE -> O(n) + O(n * k)



// ITERATIVE ------------------------------->>

int minSubsetSumDifference(vector<int>& arr, int n) {

    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[0][totSum] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {

        for (int target = 1; target <= totSum; target++) {

            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }

    }

    int mini = 1e9;

    for (int i = 0; i <= totSum; i++) {

        if (dp[n - 1][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }

    }

    return mini;

}



// SPACE OPTIMIZATION -------------------------------------------->>>


int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}




