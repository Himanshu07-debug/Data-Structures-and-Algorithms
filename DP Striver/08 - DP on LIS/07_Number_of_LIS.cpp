// dp[i] -> LIS till index i ending with arr[i] 

// Let us take a new array cnt[ ] to calculate the count and initialize it to 1

// cnt[i] -> No. of LIS where each LIS ends with arr[i] and length is dp[i]..



// If dp[i] < dp[j] + 1 .. We will update the length.
// If x is the no. of LIS ending with arr[j], then the no. of LIS ending with arr[i] will also be x

// If dp[i] == dp[j] + 1 
// We will add cnt[j] to our cnt[i] as they are also ending with arr[i] and having the length dp[i]


#include <bits/stdc++.h>
using namespace std;


int findNumberOfLIS(vector<int>& arr) {

    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]

    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++) {

        for (int prev_index = 0; prev_index < i; prev_index++) {

            if (arr[prev_index] < arr[i]) {

                if(dp[prev_index] + 1 > dp[i]){

                    dp[i] = dp[prev_index] + 1;
                    // Inherit count
                    ct[i] = ct[prev_index];


                }
                else if(dp[prev_index] + 1 == dp[i]) {
                    // Increase the count
                    ct[i] = ct[i] + ct[prev_index];
                }
            }
        }

        maxi = max(maxi, dp[i]);
        
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            numberOfLIS += ct[i];
        }
    }

    return numberOfLIS;
}



