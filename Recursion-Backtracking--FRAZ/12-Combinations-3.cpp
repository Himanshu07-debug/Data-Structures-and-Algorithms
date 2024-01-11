// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used. Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be 
// in any order.

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Here, Integers from 1 to 9, they will be distinct.. Duplicate subsets nhi banege.. 
// Normal Subset logic lagado

#include<bits/stdc++.h>
using namespace std;

void fun(int i, int k, int n, int sum, vector<int> &temp, vector<vector<int>> &ans ){

    if(k == 0){
        if(sum == n) ans.push_back(temp);
        return;
    }

    // No. of elements sum > n
    if(sum > n) return;

    if(i == 10) return;


    // skip the ith element
    fun(i+1, k, n, sum, temp, ans);

    // pick the ith element
    temp.push_back(i);
    sum += i;

    // Call
    fun(i+1, k-1, n, sum, temp, ans);

    // Backtracking
    sum -= i;
    temp.pop_back();


}


vector<vector<int>> combinationn3(int k, int n) {

    vector<vector<int>> ans;

    vector<int> temp;

    int sum = 0;

    fun(1, k, n, sum, temp, ans);

    return ans;

}