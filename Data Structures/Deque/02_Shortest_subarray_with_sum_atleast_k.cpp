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


// ANOTHER PART IS ANSWER CALCULATION ------------------->>

// In the Deque, during the removing phase i.e remove(), Check if the starting pointers i.e current dq.front() is making a valid Subarray 
// with the current indx (i) i.e pref[i] - k >= pref[st] .. 
// If it is making a Valid subarray, consider it and remove it from front becz if we keep it , it will make valid Subarray of greater length...
// the first one is the Shortest...
// pref --> 3, 5, 7, 9  ,  k = 4
// indx at 7 --> with 3 as dq.front(), makes valid subarray --> it will also make valid one with 9 but not the Shortest..
// st pointer as 5 --> 5 is not making valid one with current indx 7 , lets move ahead and we will pop 5 later when required

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

// Why do we have a prefix array and not just the initial array like in sliding window :
// Because in the sliding window when we move start (typically when we increment it) we can just substract nums[start-1] from the current sum 
// and we get the sum of the new subarray. Here the value of the start is jumping and one way to compute the sum of the current subarray in a 
// constant time is to have the prefix array.

// Starting pointers are not Contigous


void monotonic_insert(deque<int> &dq, int i, vector<long long> &pref){

    while(dq.size() && pref[dq.back()] > pref[i]){
        dq.pop_back();
    }

    dq.push_back(i);

}

int remove(deque<int> &dq, int i, vector<long long> &pref, int k){

    int ans = pref.size() + 1;

    while(dq.size() && pref[i] - k >= pref[dq.front()]){
        ans = min(ans, i - dq.front());
        dq.pop_front();
    }

    return ans;

}


int shortestSubarray(vector<int>& arr, int k) {

    int n = arr.size();

    // 1 based to not check explicity the l = 0 case
    vector<long long> pref(n+1, 0);

    for(int i=1;i<=n;i++){
        pref[i] = arr[i-1] + pref[i-1];
    }

    // arr[j] - arr[i] >= k
    // arr[i] <= arr[j] - k
    // Smaller is better, closer is better
    // far + bigger --> useless

    int ans = pref.size() + 1;

    deque<int> dq;

    for(int i=0; i <= n; i++){

        ans = min(ans, remove(dq, i, pref, k));

        cout << ans << endl;

        monotonic_insert(dq, i, pref);

    }

    if(ans == pref.size() + 1) return -1;

    return ans;

}


// LEARNINGS FROM 2 QUESTION ABOUT DEQUE ----------------->>
// 1. Try to keep the Deque monotonic ... for that --> Find the condition , you want ascending or descending..
// Anything disrupting Monotonic thing, just pop_back

// 2. Monotonic Deque code structure never change ... Try to modify those functions based on Your condition

// 3. In remove() , you remove from front AND In monotonic_insert, you make a Monotonic insert of the element in the deque

