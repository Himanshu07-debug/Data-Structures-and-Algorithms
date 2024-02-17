// A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the 
// ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a 
// fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and 
// put it in his knapsack.


// LOGIC --> 

// 2 choice -> take and Be with that item or skip that item

// GREEDY -> not, Same example of 01 - Knapsack

#include <bits/stdc++.h>
using namespace std;

int knap(int i, int mxWt, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp ){

	if(mxWt == 0) return 0;

	if(i == 0){

		return (mxWt / wt[0]) * val[0];
    
	}

	if(dp[i][mxWt] != -1) return dp[i][mxWt];

	int pick = 0;

	if(mxWt - wt[i] >= 0){
		pick = val[i] + knap(i, mxWt - wt[i], wt, val, dp);
	}

	int skip = knap(i-1, mxWt, wt, val , dp);

	return dp[i][mxWt] = max(pick, skip);

}

int knapsack(vector<int> wt, vector<int> val, int n, int mxWt) 
{
	// Write your code here

	vector<vector<int>> dp(n, vector<int>(mxWt + 1 , -1));

	return knap(n-1, mxWt, wt, val, dp);

}

// TIME -> O(n * mxWt)
// SPACE -> O(n * mxWt) + O(mxWt / min(arr))

// Iterative ------------------------------------>>

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); 


    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; 
    }

    for (int ind = 1; ind < n; ind++) {

        for (int cap = 0; cap <= W; cap++) {

            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table

        }

    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}


// SPACE OPTIMIZATION ------------------------------->>>

// Aap 1 array ka bhi use krke yha pe bhi kar sakte ho jaise knapsack me optimize kiye the...

// In Knapsack, Aap dp[i-1] pe depend kar rhe the dono choice me -> LOOP N-1 ----> 0

// Here, Aap dp[i-1] & dp[i] dono pe depend kronge.... LOOP 0 --> N-1
// dp[ind - 1][cap]  and  dp[ind][cap - wt[ind]]

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {

    vector<int> prev(W + 1, 0); 


    for (int i = wt[0]; i <= W; i++) {
        prev[i] = (i / wt[0]) * val[0]; 
    }

    for (int ind = 1; ind < n; ind++) {

        for (int cap = 0; cap <= W; cap++) {

            int notTaken = prev[cap]; 

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]]; // Maximum value by taking the current item

            prev[cap] = max(notTaken, taken); // Store the maximum value in the current DP state

        }
    }

    return prev[W]; // Return the maximum value considering all items and the knapsack capacity
}


