#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
// If there is no such subarray, return -1.

// Input: nums = [2,-1,2], k = 3
// Output: 3

// Constraints:

// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5
// 1 <= k <= 10^9


// Here, -ve elements are allowed in array...

// Binary Search + Sliding Window --> FAILS
// In BS, agar k size subarray valid hai to you should be able to declare that either all < k sized subarray or > k sized Subarray bhi valid hai.
// But becz here -ve elements are allowed , You cant say that
// [1, 2, -3, -4, -5] , k = 3
// for size = 2, [1, 2] is valid, but there is none of the subarray possible with sum >= k for the size >=2

// Two Pointers ---->  FAILS
// Now, let's take an example with negative values nums = [3, -2, 5] and target=4. Initially start=0, we keep moving the end pointer 
// until we satisfy the condition, here we will have start=0 and end=2. Now we are going to move the start pointer start=1. The sum of the 
// current subarray is -2+5=3 < 4 so we violate the condition. However if we just move the start pointer another time start=2 we 
// will find 5 >= 4 and we are satisfying the condition. And this is not what the Sliding window assumes.


// CONCLUSION ---> 2 pointers & Sliding Window fails when there is -ve no.s


// BRUTE --> O(n ^ 3)

// Better --> O(n ^ 2)
// 1 way --> Running Sum
// 2nd way --> Prefix array and then computation for i & j

// OPTIMAL --->

// Lets carry on with the Prefix array concept .......
// What we want --> 
// 1. pref[j] - pref[i] >= k  ( i.e Subarray --> sum[i+1 .... j] >= k )
// 2. Not only this, we want to minimize the length i.e we want to bring i & j closest....

// Lets assume any i & j pointers in prefix array ...

// lets say we have pref[i], and current element is pref[j] , so if we are considering subarray for any future k with i and j , i < j < k , 
// then subarray will be pref[k] - pref[i] and pref[k] - pref[j]

// Now if pref[j] < pref[i] , then we get these 2 situation, 
// 1. shorter length (k - j) as compared to (k - i). 
// 2. subarray sum(arr[k .. j]) > subarray sum (arr[k .. i]) [ let pref[k] = 7 , pref[i] = 3, pref[j] = 2 , pref[k] - pref[j] has max sum ]

// In the Question, We want the Shortest and this both condition favors for our journey to the answer...
// No need to consider pref[i] becz we get a value which has greater sum and shorter length

// This means element pref[i] is now useless 

// Simplify the equation to get the starting point -->  pref[j] - k >= pref[i] .. ( ith pointer as starting for valid Subarray )

// We have to check this to ensure that subarray considered is of sum >= k

// WHAT OPERATIONS WE WANT ???
// 1. remove_front : when we satisfy our condition of valid subarray -> pref[j] - k >= pref[i], take this length and we will move the start 
//                   pointer becz this was the closest / shortest valid Subarray possible for current start pointer

// 2. append_back : for any index that may be a future start pointer i.e if pref[j] > pref[st] , here pref[st] is not useless

// 3. remove_back : When we encounter a pref[j] whose value is less than last inserted pref[i] --> This is disrupting Monontonicity

// FOR ALL THESE OPERATIONS, DEQUE is the BOSS


// lets say deque last inserted element is pref[i] , and current element is pref[j]
// If pref[i] > pref[j] --> so , we keep popping elements from back and push current element becz this inserted elements are useless
// if pref[i] < pref[j]  --> simply insert in the deque the current j


int shortestSubarray(vector<int>& arr, int k) {

    

}

