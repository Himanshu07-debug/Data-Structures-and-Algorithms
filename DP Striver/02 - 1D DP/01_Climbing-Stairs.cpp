// Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. 
// At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 
// 0th to Nth stair.

// Input: n = 2   , n = 3
// Output: 2      , 3

// Constraints: 1 <= n <= 45  

// At each Step, we have two choices, either to move 1 step or 2 step 
// So, hum Recursion Tree banayenge, jha n se n-1 and n-2 ki two subtree hongi (Each Step We have this Two choices),
// at the last jo n reduce hoke 0 aaya wo VALID PATH tha , Agar n < 0 hua, to INVALID PATH

// LEARNING -> How to Think For Recursion, becz it is the base for DP optimization ??

//  If the problem statement asks for the following:

// Count the total number of ways
// Given multiple ways of doing a task, which way will give the minimum or the maximum output.

// We can try to apply recursion. Once we get the recursive solution, we can go ahead to convert it to a 
// dynamic programming one.

// Once the problem has been identified, the following three steps comes handy in solving the problem:

// 1. Try to represent the problem in terms of indexes.
// 2. Try all possible choices/ways at every index according to the problem statement.
// 3. If the question states
//      Count all the ways – return sum of all choices/ways.
//      Find maximum/minimum- return the choice/way with maximum/minimum output.

// SIMPLE -> Recursion is All about Trying all the Possible choices, ek to VALID honga hi, wo ans ho jayega

#include <bits/stdc++.h>
using namespace std;

// Code will be same as FIBONACCI, as Recurrence relation based on given question choices is coming that only

// RECURSION -> TLE as [ 2^45 ] will be the time complexity 

// MEMOIZATION -> 

int rec(int n,vector<int>&dp){

    if(n<0){
        return 0;
    }
    
    if(n==0){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = rec(n-1,dp) + rec(n-2,dp);

}


// TABULATION ->
int main() {

    int n=3;
    vector<int> dp(n+1,-1);
    
    dp[0]= 1;
    dp[1]= 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }

    cout<<dp[n];
    
    return 0;
}

// SPACE OPTIMIZATION -> 

int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}



