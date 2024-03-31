#include<bits/stdc++.h>
using namespace std;

// Given an integer array arr and an integer k, modify the array by repeating it k times.
// For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
// Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
// As the answer can be very large, return the answer modulo 109 + 7.


// Input: arr = [1,2], k = 3
// Output: 9



// LOGIC ---------------->>

// think in chunks ( from the smallest ) --->

// let array is [ 1, 2, -5, 2, 3 ]

// If k == 1 ----------------------> 
// Only one copy, You have to surely return the maximum subarray sum by Kadane
// Max Sum = 5


// If k == 2 ----------------------> 
// 2 copies . 
// Here there are 2 possibilities for answer -->
// Either the answer will be in the middle of the array or will be the combined of Max Suffix sum of 1st copy + Max Prefix sum of 2nd copy
// In the above array --> Middle max --> 5  , suff + pref --> 8 ( [2, 3] --> suffix of 1st copy + [1, 2] --> prefix of 2nd copy )
// 8 is maximum

// if k == 3 ---------------------->>>
// here, Comes the Interesting Part...
// [ 1, 2, -5, 2, 3, 1, 2, -5, 2, 3, 1, 2, -5, 2, 3 ]
// Here the max sum is --> [2, 3] ( 1st copy ) + [ 1, 2, -5, 2, 3 ] (2nd copy) + [1, 2]

// What the Conclusion is that we will take entire Middle subarray sum and add it with max suff , max Pref

// But can we take the entire middle subarray always ???
// in above case, sum of whole array was --> 3 , so it will contribute 3 for (k - 2) times in the Max sum and it will be surely MAX SUM

// But what if sum(arr) < 0 ?
// if we take Contribution of all middle subarray.. it will only decrease our sum... 
// in this case, max can be --> within a array OR max Suff + max pref


// CONCLUSION --------------------->>

// if sum(arr) < 0  ---> ans can be either in middle  or  the combined sum of 2 array [ Pref + suff ]

// if sum(arr) >= 0  --->  ans will be ( max Suff of copy 1  +  sum(arr)  +  max Pref of copy 1 )

long long MOD = 1e9 + 7;

long long kadane(vector<int> &arr) {

    long long maxSum = 0, sum = 0;

    for(int i=0;i<arr.size();i++){

        sum += arr[i];

        maxSum = max(maxSum, sum);

        if( sum < 0 ) sum = 0;   // ending the subarray and starting new one

    }

    return maxSum;
        
}



// Calculation of maxSuffix for 1st copy and maxPrefix for 2nd copy
pair<long long, long long> getCombinedMaxSum(vector<int> &arr, long long sum){

    long long currPrefix = 0 , currSuffix = sum;
    long long maxPrefix = 0, maxSuffix = sum;

    for(int i=0;i<arr.size();i++){

        currPrefix += arr[i];
        currSuffix -= arr[i];

        maxPrefix = max(maxPrefix, currPrefix);
        maxSuffix = max(maxSuffix, currSuffix);

    }

    return {maxPrefix, maxSuffix};

}

// SUM ---> Positive

int handlePositiveCase(vector<int> &arr, long long sum, int k){

    // for the middle maxSum
    long long ans = kadane(arr);

    // get max Suffix value and max Prefix value of arr
    pair<long long, long long> mx = getCombinedMaxSum(arr, sum);

    if(k == 1) return ans % MOD;
    else{

        long long totalMiddleSum = ((k - 2) * sum) % MOD;

        return (max(ans, mx.second + totalMiddleSum + mx.first)) % MOD;

    }

}


// SUM ---> Negative


int handleNegativeCase(vector<int> &arr, long long sum, int k){

    // for the middle maxSum
    long long ans = kadane(arr);

    // get max Suffix value and max Prefix value of arr
    pair<long long, long long> mx = getCombinedMaxSum(arr, sum);

    // If only one Copy
    if(k == 1)  return ans % MOD;
    else{

        return (max(ans,(mx.first + mx.second) % MOD)) % MOD;

    }

}


int kConcatenationMaxSum(vector<int>& arr, int k) {
        
    long long sum  = 0;

    for(int x : arr) sum += x;

    if(sum >= 0){
        return handlePositiveCase(arr, sum, k);
    }
    else{
        return handleNegativeCase(arr, sum, k);
    }

}
