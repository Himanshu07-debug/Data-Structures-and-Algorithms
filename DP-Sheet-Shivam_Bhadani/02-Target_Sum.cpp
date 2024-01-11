// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate 
// all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression " +2-1 ".
// Return the number of different expressions that you can build, which evaluates to target.

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>m;

int f(int i, vector<int>&arr, int sum, int x){

    if(i >= arr.size()){
        return sum == x ? 1 : 0;
    }

    if(m.find({i,sum})!=m.end()) return m[{i,sum}];

    int ans = f(i+1, arr, sum - arr[i], x) + f(i+1, arr, sum + arr[i], x);

    return m[{i,sum}] = ans;

}

int findTargetSumWays(vector<int>& arr, int x) {
    
    return f(0, arr, 0, x);

}

int main(){

    return 0;

}