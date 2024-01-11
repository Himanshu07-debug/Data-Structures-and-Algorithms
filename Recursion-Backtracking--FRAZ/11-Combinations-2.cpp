// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the 
// candidate numbers sum to target. Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.


// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]


// LOGIC ---------------------------------->>

// Duplicates are there in the array. We have to ensure arr[i] ignore kiye to dobara wo pick na hoye
// Sort first and In Recursion calls, Keeping while loop to handle duplicates..


#include<bits/stdc++.h>
using namespace std;

void solve(int i, int sum,int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans){

    if(sum == target){
        ans.push_back(temp);
        return;
    }

    if(i == arr.size() || sum > target){
        return;
    }

    temp.push_back(arr[i]);
    sum += arr[i];
    solve(i + 1,sum, target, arr, temp, ans);
    sum -= arr[i];
    temp.pop_back();

    // Avoiding Duplicates
    while(i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;

    solve(i + 1,sum,target, arr, temp, ans);

}


vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    vector<int> temp;

    int sum = 0;

    solve(0, sum, target, arr, temp, ans);

    return ans;
}