#include<bits/stdc++.h>
using namespace std;

// You are given two 0-indexed integer arrays nums1 and nums2, both of length n.

// You can choose two integers left and right where 0 <= left <= right < n and swap the subarray nums1[left...right] with the 
// subarray nums2[left...right].

// For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and you choose left = 1 and right = 2, nums1 
// becomes [1,12,13,4,5] and nums2 becomes [11,2,3,14,15].
// You may choose to apply the mentioned operation once or not do anything.

// The score of the arrays is the maximum of sum(nums1) and sum(nums2), where sum(arr) is the sum of all the elements in the array arr.

// Return the maximum possible score.

// Example 1:

// Input: nums1 = [60,60,60], nums2 = [10,90,10]
// Output: 210
// Explanation: Choosing left = 1 and right = 1, we have nums1 = [60,90,60] and nums2 = [10,60,10].
// The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.


// Brute ---> O(n ^ 3) 

// Creating all possible subarrays by fixing l and r & considering the subarray [l .. r] been swapped.. Keep updating max value

// Better --> O(n ^ 2) 
// Running sum or Prefix sum

// OPTIMAL --------------------------------->>

// If You select a [l .. r] range, what is exactly happening ??
// Take example of arr1 ---> total sum of arr1 se arr1[l ... r] elements removed and arr2[l .. r] added in total sum
// total sum - arr1[l ... r]  +  arr2[l ... r]

// If we want to maximize the sum of arr1 ???
// We can create a Profit array where profit[i] = arr2[i] - arr1[i] .. Itna gain honga arr1 ko iss indx se..
// Now our task is to find the max sum Subarray from the Profit array.... 
// This will be the Subarray that will be if swapped, will provide max Profit to the arr1...

// Similarly we can create a profit array for arr2 also ---> Profit2[i] = arr1[i] - arr2[i]

int maxSubArray(vector<int>& arr) {

    int maxSum = arr[0];

    arr[0] = arr[0] < 0 ? 0 : arr[0];

    for(int i=1;i<arr.size();i++){

        arr[i] += arr[i-1];

        maxSum = max(maxSum, arr[i]);

        if( arr[i] < 0 ) arr[i] = 0;   // ending the subarray and starting new one

    }

    return maxSum;
        
}


int maximumsSplicedArray(vector<int>& arr1, vector<int>& arr2) {

    int n = arr1.size();

    int sum1 = 0, sum2 = 0, mx = 0;

    vector<int> profit1(n) , profit2(n);

    for(int i=0;i<n;i++){

        sum1 += arr1[i];
        sum2 += arr2[i];        

        profit1[i] = arr2[i] - arr1[i];
        profit2[i] = arr1[i] - arr2[i];

    }

    mx = max(sum1, sum2);

    int p1 = maxSubArray(profit1);
    int p2 = maxSubArray(profit2);

    if(p1 > 0) mx = max(mx, sum1 + p1);
    if(p2 > 0) mx = max(mx, sum2 + p2);

    return mx;

}


// You can write this code shorter and Must Recommended way --->

int calculateResult(vector<int> arr1, vector<int> arr2){

    int sum = 0;

    for(int i=0;i<arr1.size();i++){

        sum += arr1[i];

        // profit array
        arr2[i] -= arr1[i];

    }

    int maxSum = arr2[0];

    arr2[0] = arr2[0] < 0 ? 0 : arr2[0];

    for(int i=1;i<arr2.size();i++){

        arr2[i] += arr2[i-1];

        maxSum = max(maxSum, arr2[i]);

        if( arr2[i] < 0 ) arr2[i] = 0;   // ending the subarray and starting new one

    }

    if(maxSum < 0) return sum;    // prefer not to swap
    
    return sum + maxSum;

}

// Above one is Generic Code that is written once and can be used for both arr1 and arr2 max sum calculation

int maximumsSplicedArray(vector<int>& arr1, vector<int>& arr2) {

    return max(calculateResult(arr1, arr2) , calculateResult(arr2, arr1));

}

// This is modularity in Code