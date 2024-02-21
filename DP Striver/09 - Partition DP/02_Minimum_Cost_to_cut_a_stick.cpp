#include<bits/stdc++.h>
using namespace std;

// Partition DP rules --->
 
// 1. Considering entire array and keeping i and j pointers. 
// Cuts array consider krnge. Ussi ke diff ways me Partition se answer differ krnge.. 

// 2. Trying out all Partitions 
// If cut[k] is made --> f(i, k-1) + f(k+1, j);

// Sorting will required of cuts array, So that K indx ke cut ke baad left subarray me < cuts[k] values and right subarray me > cuts[k] value

// Length ??
// Partition cant be made at 0 and n in rod. Its Common Sense. Also it is given -> 1 <= cuts[i] <= n - 1

// We will add 0 at first and n at last of cuts array.
// Not Length at any moment will be --> cuts[j + 1] - cuts[i - 1] 


// 3. BASE CASE --> 
// Simple Partition DP base case --> (i > j)  return 0


int minCost(int i, int j, vector<int> &cuts){

    if(i > j) return 0;

    int mi = INT_MAX;

    for(int k = i ; k <= j; k++){

        int cost = cuts[j + 1] - cuts[i - 1] + minCost(i, k-1, cuts) + minCost(k+1, j, cuts);
        mi = min(mi, cost);

    }

    return mi;

}


int minCost(int n, vector<int>& cuts) {

    sort(cuts.begin(), cuts.end());
        
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    int x = cuts.size();

    return minCost(1, x-2, cuts);

}


// Memoization ------->


int minCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){

    if(i > j) return 0;

    int mi = INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    for(int k = i ; k <= j; k++){

        int cost = cuts[j + 1] - cuts[i - 1] + minCost(i, k-1, cuts, dp) + minCost(k+1, j, cuts, dp);
        mi = min(mi, cost);

    }

    return dp[i][j] = mi;

}


int minCost(int n, vector<int>& cuts) {

    sort(cuts.begin(), cuts.end());
        
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    int x = cuts.size();

    vector<vector<int>> dp(x, vector<int> (x, -1));

    return minCost(1, x-2, cuts);

}


// TABULATION ----->

// i from x - 2 to 1
// j from 1 to x - 2

int minCost(int n, vector<int>& cuts) {

    sort(cuts.begin(), cuts.end());
        
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    int x = cuts.size();

    vector<vector<int>> dp(x, vector<int> (x, 0));

    for(int i = x - 2; i >= 1; i--){

        for(int j = 1; j <= x - 2; j++){

            if(i <= j){

                int mi = INT_MAX;

                for(int k = i ; k <= j; k++){

                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k-1] + dp[k+1][j];
                    mi = min(mi, cost);

                }

                dp[i][j] = mi;

            }

        }

    }

    return dp[1][x-2];
    

}


// SPACE OPTIMIZATION ---> curr and prev
