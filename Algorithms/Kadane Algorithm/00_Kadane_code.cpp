#include<bits/stdc++.h>
using namespace std;

// GREEDY ???
// We make the disjoint part subarray of the Array. -ve element will be our breaking pt. for prev subarray..
// this is becz taking -ve will not contribute to max sum..
// Eg -> [ 2, 1, -3, 4, 5, 3, -7, 9 ]
// According to Greedy --> [ 2, 1 ] , [ 4, 5, 3 ] , [ 9 ]  --> max => 12
// But is it true ??
// [ 4, 5, 3, -7, 9 ] --> 14 ( more than 12 )

// Taking -ve can lead us to max ans --> GREEDY FAIL


// RECURSIVE KADANE ( MEMOIZATION ) -------------------------------->>

// Here, there can be 3 possibilities for any indx i ----->
// 1. max subarray at left of i
// 2. max subarray including i
// 3. max subarray to the right of i

// the 1st choice is of the PAST and hence it is out of our scope / control
// 2nd choice and 3rd choice are under our control

// 2nd choice --> for indx i, I can decide, either to include i in the current subarray [continuing the curr subarray] or 
//                do not include i ( End the current subarray here )

// 3rd choice --> Either to start from the current indx i or leave the starting part for future indexes.


// STATE and RECURRENCE RELATION ------------------------------------>>

// Parameters --> ( i, started )

// if started = true ==> max( 0 , arr[i] + (i+1, started) )
// End the started subarray ( 0 ) OR continue with the started subarray

// if started = false ==> max( (i + 1, started) , arr[i] + (i + 1, !started ) )
// Start a new subarray with indx i  OR  Leave it for future


// BASE CASE --> 
// if started == true ---> return 0
// else return INT_MIN;


int kadane(int i, int started, vector<int>& arr , vector<vector<int>> &dp){

    if(i == arr.size()){
        if(started) return 0;
        else return INT_MIN;
    }

    if(dp[i][started] != INT_MAX ) return dp[i][started];

    if(started){
        return dp[i][started] = max(0, arr[i] + kadane(i+1, started, arr, dp));
    }
    else{
        return dp[i][started] = max(kadane(i + 1, started, arr, dp) , arr[i] + kadane(i+1, 1-started, arr, dp  ));
    }

}


int maxSubArray(vector<int>& arr) {

    vector<vector<int>> dp(arr.size() , vector<int> (2, INT_MAX));

    return kadane(0, 0, arr, dp);
        
}

// TIME --> O(n * 2) [ BEST ]


// ITERATIVE KADANE -------------------------->>


// BRUTE --> O(n ^ 3)
// BETTER --> O(n ^ 2) [ running Sum ]
// BEST --> O(n) 

int kadane(vector<int>& arr) {

    int maxSum = arr[0];

    arr[0] = arr[0] < 0 ? 0 : arr[0];

    for(int i=1;i<arr.size();i++){

        arr[i] += arr[i-1];

        maxSum = max(maxSum, arr[i]);

        if( arr[i] < 0 ) arr[i] = 0;   // ending the subarray and starting new one

    }

    return maxSum;
        
}
