// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

// DRAW THE RECURSION TREE WITH PICK - SKIP LOGIC OF THE ith NUMBER

// NAIVE --> 
// Create all Possible Subsets and in the Base case, check If it is of k size , store it in answer vector, otherwise only return

// BETTER -->
// We can Keep track of size, if it is equal to k, then we will not make further unecessary calls.. We will store it and return

// MORE OPTIMIZATION --->
// Agar K bigger hai than the remaining elements wo mai add krunga, tab subset k size ka hi ban hi nhi sakta .. Why to make then this calls ???
// If k > remaining elements


// TIME --> O(2^n)
// Becz of our 2 optimizations, we have reduced the Calls/node number a lot...

// SPACE -> O(n)

#include<bits/stdc++.h>
using namespace std;

void subset(int i, int n, int k, vector<int> &temp, vector<vector<int>> &ans){

    // Optimization 1 
    if(k == 0){
        ans.push_back(temp);
        return;
    }

    if(i > n) return;  

    // Optimization 2 -> 
    // k > remaining elements 
    if(k > n-i+1) return;

    temp.push_back(i);

    subset(i+1, n, k-1, temp, ans);

    temp.pop_back();

    subset(i+1, n, k, temp, ans);

}

vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> ans;

    vector<int> temp;

    subset(1, n, k, temp, ans);

    return ans;

}