// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the 
// chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of 
// the chosen numbers is different.

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.


// Distinct Integers hai, Duplicate Subsets nhi banege... Use normal pick - not_pick logic

// TIME -> 
// For each Subproblem there are n choices ->  
// O(2 ^ k) - where n is the length of the array, k is the length of the longest possible combination (namely target / minInArray).

// SPACE --> O(target) + space taken by ans


#include<bits/stdc++.h>
using namespace std;

void solve(int i, vector<int> &arr, int target, int sum, vector<int> &temp, vector<vector<int>> &ans){

    if(sum == target){
        ans.push_back(temp);
        return;
    }

    if(sum > target) return;

    if(i >= arr.size()) return;        

    // Skipping the ith number
    solve(i+1, arr, target, sum, temp, ans);

    // Picking the ith number
    sum += arr[i];
    temp.push_back(arr[i]);

    // call
    solve(i, arr, target, sum, temp, ans);

    // Backtracking
    temp.pop_back();
    sum -= arr[i];

}


vector<vector<int>> combinationSum(vector<int>& arr, int target) {


    vector<vector<int>> ans;

    vector<int> temp;

    int sum = 0;

    solve(0, arr, target, sum, temp, ans);

    return ans;

    
}

// If any Q.s it is said that -> Elements in each Combination must be in non-decreasing order...
// This means each combinations in the ans vector should be in Sorted order
// For this, hume sorted array bhejna padega recursion ko subset bnane ke liye... Sort arr and then call solve() function