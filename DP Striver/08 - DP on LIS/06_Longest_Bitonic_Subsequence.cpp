#include <bits/stdc++.h>
using namespace std;


// BITONIC SUBSEQUENCE ---->

// LIS we know. Bitonic is just like a Mountain.

// If You view the Mountain from the right side, it is nothing, but LIS from n-1 to any indx i
// From the Left view, we are Aware about LIS.

// So, for any indx i, if we know the length of the LIS from 0 to i and length of LIS from n-1 to i, we can sum this length to get the entire 
// Bitonix Subsequence length of the respective mountain.

// dp1[i] -> LIS from 0 to i
// dp2[i] -> LIS from n-1 to i

// For any indx i, Valid Bitonic Subsequence length --> dp1[i] + dp2[i] - 1 ( ith element 2 baar consider hua, remove its one instance )
// Find the max Bitonic Subsequence from indx 0 to n-1

int longestBitonicSequence(vector<int>& arr, int n) {


    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]

    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

    // Calculate the longest increasing subsequence
    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 1; i >= 0; i--) {
        for (int prev_index = n - 1; prev_index > i; prev_index--) {
            if (arr[prev_index] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
    }

    int maxi = -1;

    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}