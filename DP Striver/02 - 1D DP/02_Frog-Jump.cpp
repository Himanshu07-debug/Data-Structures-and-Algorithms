// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
// At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog 
// jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]). 
// We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

// N=4, height[] = {10,20,30,10}
// Ans : 20 
// Move 1 step from 10 -> 20 AND then move 2 step from 20 -> 10  : Energy = (20-10) + abs(10-20) => 20


// As the problem statement states to find the minimum energy required, two approaches should come to our mind,
// GREEDY and DYNAMIC PROGRAMMING.

// Why Greedy will not Work ??
// The total energy required by the frog depends upon the path taken by the frog. If the frog just takes the cheapest
// path in every stage it can happen that it eventually takes a costlier path after a certain number of jumps

// Whenever You have to verify that Greedy will work or not, think aout some test cases where GREEDY can Fail -
//  [30,10,60,10,60,50]
// GREEDY => 30 -> 10 -> 10 -> 50  [ 20 + 0 + 40 = 60 ]
// Not Greedy => 30 -> 60 -> 60 -> 50 [ 30 + 0 + 10 = 40 ]

// MEANS we have to try all possible paths -> RECURSION

// RECURSION -------------------------------------------------->

#include <bits/stdc++.h>
using namespace std;

int Solve(int ind, vector<int>& height){

    if(ind == 0) return 0;

    int jumpTwo = INT_MAX;
    int jumpOne= Solve(ind-1, height)+ abs(height[ind] - height[ind-1]);

    if(ind > 1)
        jumpTwo = Solve(ind-2, height)+ abs(height[ind] - height[ind-2]);
    
    return min(jumpOne, jumpTwo);
}

// TIME -> O(2^N)




// OPTIMIZATION -> Look for Overlapping Subproblems

// MEMOIZATION ------------------------------------>

int solve(int ind, vector<int>& height, vector<int>& dp){

    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);

    if(ind > 1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind] = min(jumpOne, jumpTwo);

}

int main() {

    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    vector<int> dp(n,-1);
    cout<<solve(n-1,height,dp);

}



// TABULATION -------------------------------->>

int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();

  vector<int> dp(n,-1);
  dp[0]=0;

  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }

  cout<< dp[n-1];

}

// SPACE OPTIMIZATION -------------------------------->>

int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;

      int jumpOne= prev + abs(height[i]-height[i-1]);

      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i = min(jumpOne, jumpTwo);

      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}

