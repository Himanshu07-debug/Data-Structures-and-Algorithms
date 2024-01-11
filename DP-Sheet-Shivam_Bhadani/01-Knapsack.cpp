// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
// 1 ≤ n ≤ 1000
// 1 ≤ x ≤ 1000
// 1 ≤ wt[i] ≤ 1000
// 1 ≤ val[i] ≤ 1000



// KNAPSACK --> Space Optimization is Possible


#include<bits/stdc++.h>
using namespace std;

int knapSack(int x, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i=1;i<=n;i++){

        for(int j=0;j<=x;j++){

            int pick = 0;

            if(j >= wt[i-1])  pick = val[i-1] + dp[i-1][j - wt[i-1]];

            int skip = dp[i-1][j];

            dp[i][j] = max(pick, skip); 

        }

    }

    cout << dp[n][x] << endl;


}

int main(){

    return 0;

}

