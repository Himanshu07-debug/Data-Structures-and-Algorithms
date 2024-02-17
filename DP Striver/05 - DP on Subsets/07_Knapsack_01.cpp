// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of 
// value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that 
// a thief can generate by stealing items.


// LOGIC ------------------------------------------------>>

// GREEDY will not work ..
// ex -> wt = [3, 2, 5] , profit = [30, 40, 60] , cap = 6
// ANS ==> Greedy -> 60, non - greedy -> 70

// Pick - not Pick logic .... 
// Each time , thief have 2 choice, Either to steal that item or skip it


// MEMOIZATION --------------------------------->>>

#include <bits/stdc++.h>
using namespace std;

int knap(int i, int mxWt, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp ){

	if(mxWt == 0) return 0;

	if(i == 0){
        // If cap >= wt[0] , then only we can take the 0th index item
		if(mxWt >= wt[0]) return val[0];
		else return 0;
	}

	if(dp[i][mxWt] != -1) return dp[i][mxWt];

	int pick = 0;

	if(mxWt - wt[i] >= 0){
		pick = val[i] + knap(i-1, mxWt - wt[i], wt, val, dp);
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

// TIME -> O(n * w)
// SPACE -> O(n * w) + O(n)


// ITERATIVE --------------------->>

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // I can steal the val[0] for all cap >= wt[0]
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++) {

        for (int cap = 0; cap <= W; cap++) {

            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;

            if (wt[ind] <= cap) {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];

}


// SPACE OPTIMIZATION --------------------------->>

// Hum kar sakte hai aaram se curr and previous vector leke , Isme hum 2 vector use kar rhe hai...
// Can we can more optimize it i.e using 1 vector ????

// Phle 2 vector wla btana...

// Koi bhi w ka answer prev ke left wale values pe dependable, not on the right side values....
// Hum Cap = W -> 0 tk chale and each time prev ko hi update kare to ho jayega..... Kyuki aage ke states W-1 -> 0 , R.H.S nhi lenge.....

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {

    vector<int> prev(W + 1, 0);

    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {

            int notTaken = prev[cap];
            int taken = INT_MIN;

            if (wt[ind] <= cap) {
                taken = val[ind] + prev[cap - wt[ind]];
            }

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[W];

}


