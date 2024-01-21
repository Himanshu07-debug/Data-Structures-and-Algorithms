// Tabulation is a ‘bottom-up’ approach where we start from the base case and reach the final answer that we want.

// Apko sirf Memoization ko Iterative manner me likhna hai by Considering the Base Case at the beginning

// MEMOIZATION -> TABULATION :

/*
1. Declare the Base case
2. Express all states in a For loop (Recursion Tree ke States)
3. Copy the Recursion and Write
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n=5;

    vector<int> dp(n+1,-1);
    
    // Declaring the Base Case
    dp[0]= 0;
    dp[1]= 1;
    
    // All states covered in the For Loop
    for(int i=2; i<=n; i++){

        // RECURSION STATES ->>>
        dp[i] = dp[i-1]+ dp[i-2];

    }

    cout<<dp[n];
    return 0;
}



// Time Complexity: O(N)
// Reason: We are running a simple iterative loop

// Space Complexity: O(N)
// Reason: We are only using an external array of size ‘n+1’.


// *************************** ITERATIVE vs RECURSIVE *************************************

// 1. ==>
// In Recursion, For subproblem answers, You calls the function becz you are not sured that the Subproblem is already solved or not...
// Yeah subproblem jab call hota hai, then if(dp[n] != -1) yha pe check hota hai computed hai ki nhi...
// That's why -->  dp[n] = fib2(n-1) + fib2(n-2);

// In Iterative, You make ensured for the state i that all of its required subproblems are already solved ....
// That's why --> dp[i] = dp[i-1] + dp[i-2];
// We are assured that dp[i-1] and dp[i-2] are solved ..


// 2. ==>
// In Memoization, You give any random input and you are assured that you will get an answer becz You handle every edge cases...
// But in Iterative, you cant give Random Input 
// That's why, Recursive DP is EASY.. becz any random I/P can be given , they will be handled...  

// ************************* FLOW OF STATES MATTER while writing the ITERATIVE CODE ****************************************