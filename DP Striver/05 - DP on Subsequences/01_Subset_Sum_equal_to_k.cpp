// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ 
// with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

// 1 <= N <= 10^3
// 0 <= ARR[i] <= 10^9
// 0 <= K <= 10^3

// 4 5
// 4 3 2 1
// 5 4
// 2 5 1 6 
// Ans -> True
//        False


// LOGIC ----------------------------->>

// Subset Pick - skip logic ..

// Recursion Time -> O(2^n) , O(n)


// MEMOIZATION ------------------------>>

// DP On Subsequences, (indx , target) are index parameters ( MUST ), inme add dusre ho sakte hai

// There are Overlapping Subproblems, Left Subtree ho jaane ke baad Right Subtree me dekhna
// Bigger the Input, Bigger the Tree, more Overlapping Subproblems...



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


bool subsetSumToK(int n, int k, vector<int>& arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);

}

// TIME -> O(n * k)
// Space -> O(n * k) + O(n)


// ITERATIVE --------------------------->>

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Just apply the Recursion Base case Logic here

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }


    for (int ind = 1; ind < n; ind++) {

        for (int target = 1; target <= k; target++) {

            bool notTaken = dp[ind - 1][target];


            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }


            dp[ind][target] = notTaken || taken;

        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}




// SPACE OPTIMIZATION -------------------------------------------->>



bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    // vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    vector<bool> prev(k+1, false);

    if(arr[0] <= k){
        prev[arr[0]] = true;
    }

    prev[0] = true;

    for(int i=1;i<n;i++){

        vector<bool> curr(k+1, false);
        curr[0] = true;

        for(int s = 1; s <= k;s++){

            bool skip = prev[s];

            bool pick = false;

            if(s >= arr[i]){
                pick = prev[s - arr[i]];
            }

            curr[s] = skip | pick;

        }

        prev = curr;

    }

    return prev[k];


}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}


