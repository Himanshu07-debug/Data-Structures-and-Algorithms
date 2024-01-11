// Given an integer array arr and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are 
// all equal.

// Input: arr = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

// 1 <= k <= arr.length <= 16
// 1 <= arr[i] <= 10^4
// The frequency of each element is in the range [1, 4].


// LOGIC ------------------------------------------>>

// Inorder to make equal sum in all the K Buckets -> sum(arr) % k == 0
// And the equal sum that can be make in each bucket will be --> sum(arr) / k

// There is a case when this condition will fail -->
// Suppose arr = [7 9 5] , k = 3  ..... Yha sum(arr) % k = 0 , But aap equal sum subset me nhi kar sakte 

// We will go Bucket-wise and at a moment, we will fill a Single Bucket, If it is Successfully filled with the Required sum, We will move to 
// fill another bucket.. If We successfully fill all the buckets with required sum, return...

// For each Bucket, we will ask each elements in the arr, either you have to go in it or not .. i.e pick - not_pick logic
// Simply, We are checking all generating all Possible Combinations Sum to check either we can get the Required sum in any of the Combination.. 


#include<bits/stdc++.h>
using namespace std;

bool Combination(int i, int bucketSum, int bucketNumber, int k, int requiredSum, vector<int> &arr, vector<int> &alreadyPicked){

    // All buckets get filled
    if(bucketNumber == k + 1) return true;

    if(bucketSum == requiredSum){

        return Combination(0, 0, bucketNumber + 1, k, requiredSum, arr, alreadyPicked);

    }

    if(bucketSum > requiredSum) return false;

    if(i == arr.size()) return false;

    // if already picked
    if(alreadyPicked[i] == 1){

        return Combination(i+1, bucketSum, bucketNumber, k, requiredSum, arr, alreadyPicked);

    }
    else{

        // pick the ith element
        bucketSum += arr[i];
        alreadyPicked[i] = 1;

        bool pick = Combination(i+1, bucketSum, bucketNumber, k, requiredSum, arr, alreadyPicked);

        // Backtracking
        bucketSum -= arr[i];
        alreadyPicked[i] = 0;

        bool skip  = Combination(i+1, bucketSum, bucketNumber, k, requiredSum, arr, alreadyPicked);

        // If any one of 2 returns true, return true
        return pick | skip;


    }

}


bool canPartitionKSubsets(vector<int>& arr, int k) {
        
    int n = arr.size();
    vector<int> alreadyPicked(n,0);  // to keep track of the picked elements...

    int a = 0;

    for(int x : arr) a += x;

    if( a % k == 0) return false;

    int requiredSum = a / k;

    int sum = 0;

    return Combination(0, 0, 1, k, requiredSum, arr, alreadyPicked);

}


// TIME --> O(2 ^ (k * n))
// height of the Tree -> O(n) and For Each Bucket, tree banega, O( k * n )

// SPACE --> O(k * n)

// This will Give TLE... Iska Optimized Version hai with DP...
