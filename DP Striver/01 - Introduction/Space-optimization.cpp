// In Some Questions, More Space Optimization is Possible [ Representing States in Variables ]

// Whenever you have to think for the Space Optimization, Just make the array of dots representing indx and see a 
// Single dot dependencies on other previous dots

#include <bits/stdc++.h>
using namespace std;

int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){

      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;

  }

  cout<<prev;

  return 0;
  
}

// Time Complexity: O(N)
// Reason: We are running a simple iterative loop

// Space Complexity: O(1)
// Reason: We are not using any extra space

// REMEMBER -> 99% of the DP problem Memoization se hi ho jaate, yeah dono optimized Approach me agar confident ho
//             tabhi aage badhna

// TABULATION To usually ho jaata hai sabme lekin Space Optimization is not possible in every question