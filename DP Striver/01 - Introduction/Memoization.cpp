// DP is an Optimization to the all of the Recursion Problems having Overlapping Subproblems ( V.V.IMP )

// Dynamic Programming can be described as storing answers to various sub-problems to be used later whenever 
// required to solve the main problem.

// OVERLAPPING SUBPROBLEMS -> Yeah mostly Recursion Tree se Figure out hote hai, jisko ek baar calculate kar liye
//                           kahi pe bhi Recursion Tree me, usse Again Calculate karna 

// In Fibonacci, for n=5, In the Left Subtree, fib(2), fib(3) is calculated, And right subtree me fib(2), fib(3) 
// calculate hue hai, 

// NOTE -> IN DP, hum again Calculate nhi karenge, first time me hi uske answer ko khi store kar lenge

// FIBONNACI EXAMPLE -------------->>

// RECURSIVE CODE ::
#include <bits/stdc++.h>
using namespace std;

int fib(int n){

    // Base Case :
    if(n <= 1) return n;

    return fib(n-1) + fib(n-2);
}


// Memoization : TOP DOWN APPROACH ( n = 5 se 0 )

/*

Any recursive solution to a problem can be memoized using these three steps ------------------------>

1. Create a dp[n+1] array initialized to -1.

2. Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already 
   calculated using the dp array(i.e dp[n]!= -1 ). If yes, simply return the value from the dp array.
   
3. If not, then we are finding the answer for the given value for the first time, we will use the recursive 
    relation as usual but before returning from the function, we will set dp[n] to the solution we get.

*/

int fib(int n, vector<int>& dp){

    // Base Case :
    if(n <= 1) return n;
    
    // If n was previously Calculated
    if(dp[n]!= -1) return dp[n];

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}


int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<fib(n,dp);
  return 0;
}

// TIME -> O(N)
// The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of 
// new subproblems we solve is ‘n’. Hence total time complexity is O(N).

// SPACE -> O(N) + O(N)
// We are using a recursion stack space(O(N)) and an array (again O(N)).
// Therefore total space complexity will be O(N) + O(N) ≈ O(N)


