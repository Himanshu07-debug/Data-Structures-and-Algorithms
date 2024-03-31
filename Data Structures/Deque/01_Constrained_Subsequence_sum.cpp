#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two 
// consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

// Input: nums = [10,2,-10,5,20], k = 2
// Output: 37    [10, 2, 5, 20].

// Input: nums = [-1,-2,-3], k = 1
// Output: -1
// Explanation: The subsequence must be non-empty, so we choose the largest number.

// Input: nums = [10,-2,-10,-5,20], k = 2
// Output: 23    [10, -2, -5, 20].


// 1 <= k <= nums.length <= 10^5        ------------>>> DP fails
// -10^4 <= nums[i] <= 10^4


// Same like LIS....
// Let dp[i] -> maximum sum of the subsequence ending at indx i..

// for any indx, we can go to i - 1 to i - k indexes...
// So we will take max (dp[i - 1] , dp[i - 2] , dp[i - 3], ... , dp [i - k] )..
// and will add arr[i] to the max value....

// The Operation will take O(n * k) time...

// We can optimize it...
// j - i <= k ... --> Here we are dealing with k sized windows...

// for indx i, I want the previous Window maximum made from i - 1 to i - k
// This is same as Sliding window maximum ... Using deque, we will get window max in O(1)

void monotonic_insert(deque<int> &dq, int i, vector<int> &dp){

    while(!dq.empty() && dp[dq.back()] < dp[i]){
        dq.pop_back();
    }

    dq.push_back(i);

}


void remove(deque<int> &dq, int indx, int k){

    while(!dq.empty() && indx - dq.front() > k){
        dq.pop_front();
    }

}


int constrainedSubsetSum(vector<int>& arr, int k) {

    int n = arr.size();

    vector<int> dp(n, 0);

    deque<int> dq;

    for(int i=0;i<n;i++){

        remove(dq, i, k);

        // if previous max is +ve, then only it contributes to the subsequence sum, otherwise I will start subsequence from the current indx
        if(dq.size() && dp[dq.front()] > 0){
            dp[i] = arr[i] + dp[dq.front()];
        }
        else{
            dp[i] = arr[i];
        }

        monotonic_insert(dq, i, dp);

    }

    int mx = INT_MIN;

    for(int i=0;i<n;i++){
        mx = max(mx, dp[i]);
    }

    return mx;
        
}