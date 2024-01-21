// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

// Brute : O(n^3) -> Getting all subarrays and calculating max length
// Naive : O(n^2) -> Subarray ke sum se lena dena hai, O(n^2) se bhi ho jayega
// Better : O(n) -> Hashing ( Becomes OPTIMAL when array contains negative and positive integers both )
// Optimal : O(n) -> 2 pointers ( sum <= k or sum >= k wali condition nhi, sum == k, so +ve elements chahiye )


// We can use a Hashmap to efficiently do this ( Jab bhi cnt jaisi cheeze rhti hai, hum hashset use nhi krte )

// REMEMBER -> Worst case complexity of Hashmap/HashSet is O(n) , Interviewer can say do not use this, then use MAP


#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    
    int n = arr.size(); // size of the given array.
    unordered_map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

