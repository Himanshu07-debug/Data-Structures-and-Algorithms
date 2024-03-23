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


