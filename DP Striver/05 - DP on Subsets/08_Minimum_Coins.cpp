// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of 
// elements you have to take to reach the target sum ‘X’.

// LOGIC ------------------------------------->>>

// GREEDY ???

// {1, 2, 3} , x = 7
// Take the maxi -> 7/3 => 2 coins of 3
// Rem x = 1 , Take the maxi -> 1 / 1 => 1 coin of 1
// Min. 3 coins are required...
// This gave the Right answer....

// But is this hold everytime ??

// {9, 6, 5, 1} , x = 11
// Take the maxi -> 11/9 => 1 coin of 9
// Rem x = 2, 2/1 => 2 coins of 1
// Min. 3 coins are Required...

// But If we take {6, 5} -> 11 .. (Only in 2 coins) =======>> GREEDY FAILS

// Recursion ---------------------->>

// Yha pe 2 choice hai, either to pick it and be with that coin or skip that coin....


// MEMOIZATION -------------------------------------->>>


#include <bits/stdc++.h> 
using namespace std;

int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(T == 0) return 0;

    if(ind == 0){

        if(T % arr[0] == 0)     return T / arr[0]; 
        else
            return 1e9; 
    }
    
    if(dp[ind][T] != -1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);
    
    int taken = 1e9; 

    if(arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);
        
    return dp[ind][T] = min(notTaken, taken);

}


int minimumElements(vector<int>& arr, int T){
    
    int n = arr.size();
    
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));
    
    int ans =  minimumElementsUtil(arr, n - 1, T, dp);
    
    if(ans >= 1e9)
        return -1;
    
    return ans;

}

// TIME -> 2 ^ (target / min(arr))
// SPACE -> O(target / min(arr)) 

// That can be Huge if target is Bigger....

// MEMOIZATION --> 
// Time -> O(n * target)
// Space -> O(target) + O(n * target)


// ITERATIVE ------------------------------------------------->>>

int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {

            int notTake = dp[ind - 1][target];
            

            int take = 1e9; 
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n - 1][T];
    
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}


// NOTE --->
// SomeTimes Memoization Give You AC, but Tabulation not... WHY ????
// In Tabulation, Aap pure States calculate krte ho, But in Memoization, It might be possible ki aapne kuch states (unnecessary states) compute
// nhi kiya ho ( Recusrsion Valid States ke liye use krte hai )

// For loop in Iterative me by default all states compute honge, even though they are unnecessary...

// Iterative ko Space Optimized kro


// SPACE ----------------------------->>

int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create two vectors to store the previous and current DP states
    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = prev[target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the current DP state
            cur[target] = min(notTake, take);
        }
        // Update the previous DP state with the current state for the next iteration
        prev = cur;
    }
    
    // The answer is in the last row of the DP table
    int ans = prev[T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}

