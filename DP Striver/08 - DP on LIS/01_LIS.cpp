#include<bits/stdc++.h>
using namespace std;

// NAIVE ----------------->>

// Power set code.. All subsets in an array , Check for Increasing --> Take max length

// RECURSIVE ---------------------------------->>

int getAns(int arr[], int n, int ind, int prev_index) {

    if (ind == n)
        return 0;
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind);
    }
    
    return max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    
    return getAns(arr, n, 0, -1);      // prev == -1 --> No Parent

}

// NOTE --->> In LIS, plz go from 0 --> n-1 becz we had tried for n-1 --> 0 ... Tabulation nhi ho paaya


// MEMOIZATION --------------------------------->>

// MOST IMP THING --->
// prev == -1 hai, dp array ke index me kaise, How to handle ???

// Don't Change the Code, just Observe --> prev moves from -1 to n-1 ...
// Inorder to make it fit into array indexes ---> Shifting of indexes. We will store prev -1 value in 0 index at dp , 0 at 1 , etc

// Don't Touch prev, We only have to update the dp indexes --> prev to prev + 1


// REMEMBER --> In DSA, once You found that Your code runs, While Optimizing Do less modification in it, becz it might happen that ki more 
//              modification ke reason se Code na chale ( Wrong answer )


int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {

    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);

}

int longestIncreasingSubsequence(int arr[], int n) {

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getAns(arr, n, 0, -1, dp);
    
}


// TABULATION ------------------------------------>>

// 2nd loop -->
// If we look closely at the recursive tree, we will see a pattern that the second parameter, prev_index is always smaller than the 
// first parameter ind. Therefore we will write the for loop for prev_index to start from ind-1 till -1.

// In simple Words --> For any i, valid prev -> i-1 to -1

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind--){
        for (int prev_index = ind-1; prev_index >=-1; prev_index--){              // You can reverse it also  
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];

}


// SPACE OPTIMIZATION --------------------------------->>

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> next(n+1,0);
    
    vector<int> cur(n+1,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for (int prev_index = ind-1; prev_index >=-1; prev_index--){
            
            int notTake = 0 + next[prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
                take = 1 + next[ind+1];
            }
    
            cur[prev_index+1] = max(notTake,take);
        }
        next = cur;
    }
    
    return cur[0];
}


