// We are given a rod of size ‘N’. It can be cut into pieces. Each length of a piece has a particular price given by the price array. 
// Our task is to find the maximum revenue that can be generated by selling the rod after cutting( if required) into pieces.

// Note:
// 1. The sizes will range from 1 to ‘N’ and will be integers. [ Array ka indx rod length hai ] arr[1] = 3 i.e 1 length ke rod ka price 3
// 2. The sum of the pieces cut should be equal to ‘N’.
// 3. Consider 1-based indexing.

// N = 5
// price = 2 5 7 8 10    
// All possible partitions are:
// 1,1,1,1,1           max_cost=(2+2+2+2+2)=10
// 1,1,1,2             max_cost=(2+2+2+5)=11
// 1,1,3               max_cost=(2+2+7)=11
// 1,4                 max_cost=(2+8)=10
// 5                   max_cost=(10)=10
// 2,3                 max_cost=(5+7)=12
// 1,2,2               max _cost=(1+5+5)=12    

// Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.



// LOGIC --------------------------------->>

// UnBounded Knapsack ke Pattern ka Problem...

#include <bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp) {

    if(N == 0) return 0;

    // Base case: if we're at the first item
    if (ind == 0) {

        return N * price[0];
    }
    

    if (dp[ind][N] != -1)
        return dp[ind][N];
        

    int notTaken = 0 + knapsackUtil(price, ind - 1, N, dp);
    

    int taken = INT_MIN;
	int rod_length = ind + 1;

    if (rod_length <= N)
        taken = price[ind] + knapsackUtil(price, ind, N - rod_length, dp);
        
    return dp[ind][N] = max(notTaken, taken);

}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Create a DP table
    
    return knapsackUtil(price, n - 1, n, dp);

}


// ITERATIVE
// SPACE -> 1 vector se kar sakte ( unBounded Knapsack ka Subproblem hai )




