// Given an integer array arr that may contain duplicates, return all possible subsets(the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: arr = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// 1 <= n <= 10


// Draw the Recursion tree by our previous subset-1 logic .. and See where We are getting Problems...
// if we pick 2, uska ek subtree banega, and if ignore, skip ka ek subtree.. We have to ensure that ki 2 ab aage Skip wale subtree me na aaye..
// WHY ?? [1, 2, 1, 2]
// If we are at 1, we picked 2, {1, 2} and skipped -> {1}
// To {1, 2} last tk skip hoke {1, 2} hi rah sakta hai ek child me, if agar {1} me 2 add kar diye to iske bhi subtree me ek child {1,2} and also 
// if remaining elements honge wo ban jayenge... Means Bigger {1,2} ke Subtree ka ek sub-part of {1,2} ki subtree ban jayegi..


// For Duplicate Checking, we will sort the array.. So that same elements together aa jaaye..


#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int indx){

    if(indx == arr.size()){
        ans.push_back(temp);
        return;
    }

    // picking arr[i]
    temp.push_back(arr[indx]);

    solve(arr,temp,ans,indx + 1);

    // popping the picked element .. CLEANING
    temp.pop_back();

    // Duplicate handling
    while(indx + 1 < arr.size() && arr[indx] == arr[indx + 1]) indx++;
    
    solve(arr,temp,ans,indx + 1);

}

vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    
    vector<vector<int>> ans;

    // sort the array
    sort(arr.begin(),arr.end());

    vector<int> temp;

    solve(arr, temp, ans, 0);

    return ans;

}

// TIME --> O(2 ^ n) [ Worst case -> when all elements are Unique ]

// Space -> O(n) + O(n) (Call stack)