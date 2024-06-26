// Given a chain of matrices A1,…, An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices.

// Input Structure -> [10, 20, 30]
// There are 2 matrix -> 10 * 20  &&  20 * 30

// What is this Problem stating ?
// We know that if there are n matrix, Your no. of operation varry based on your Selected pattern of multiplication.. 
// For eg -> There are 4 matrix -> A B C D
// Possible way -> ( A B ) ( C D )  or A (B C D) or A ( B ( C D ))  or (A (B C )) D .. so on

// Varying no. of operation ->
// Let A = 10 * 30 , B = 30 * 5 , C = 5 * 60
// If (A B) C --> ( 10 * 30 * 5 ) [AB] + (10 * 5 * 60) ==> 4500 operation
// If A (B C) --> ( 30 * 5 * 60 ) [BC] + (10 * 30 * 60) ==> 27000 operation..

// Huge diff on the final ans based on the Selection of Pattern --> PARTITION DP

// Question -> Min. no. of operation to multiply n matrices..

// RULES FOR PARTITION DP -->

// 1. Start with the entire block/array and mark it with i,j. We need to find the value of f(i,j). 

// NOTE -> In partition DP, you have to consider the entire array

// For array of n+1 size, we will considered n matrices from no. 1 to n-1
// For each indx matrix, The actual matrix is --> arr[i - 1] * arr[i] i.e ith matrix is this

// So i = 1 and j = n-1 [ indexes includes n matrices ]
// f(i,j) -> Min. operation to get the Product of matrix from Mi to Mj



// 2. Try all Partitions -->

// We can partition from indexes i to j - 1 for the range of matrices [ i ... j ]
// Let k be the indx of partition.. So partition will be --> 
// f(i, k) & f(k+1, j)

// If You make partition from k = i+1 to j
// Then partition -> f(i, k-1) & f(k, j)

// All possible partition me se min. ans selected

// this is LR dp, every subproblem will be independent... 
// if i have to calculate the number of operation due to current partition , see the observation --->

// let the matrix are A B C D and dimension --> [ 10 20 30 40 50 ], l = 1 and r = 4

// if partition made at A --> (A) (B C D)
// we will not go bottom up i.e BCD ko solve krnge and the operation will be updated here... In matrix multiplication, we can do it directly..
// what is the resultant matrix dimension of (B C D) --> 
// take any internal combination like  --> B (C D) or (B C) D or B C D --> all will lead to dimension --> B row * D col
// Any if we multiply this with A --> A row * D col

// take one more example --> (A B) (C D) --> partition made at B
// dimension --> A row * B col   &&& C row and D col
// resultant --> A row * D col

// see You can directly find out the operation....
// for range (l r), make partition at any K ( l <= k <= r-1 ) .... arr[l - 1] * arr[k] * arr[r]

// arr[l-1] and arr[r] remains common as bound for the current range... only K value changes .. becz it is based on partition... 


// RECURSION ------------------------------------>>>

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr, int i, int j){
    
    // base condition
    if(i == j)
        return 0;
        
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k <= j-1; k++){
        
        int ans = fun(arr,i,k) + fun(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    // the complete block array with i and j range
    int i = 1;
    int j = N-1;

    return fun(arr,i,j);
    
    
}

// TIME -> Exponential

// MEMOIZATION --->>

// changing Parameters -> i and j

int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    
    // base condition
    if(i == j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    // partioning loop
    for(int k = i; k<= j-1; k++){
        
        int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        
        mini = min(mini,ans);
        
    }
    
    return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
    
    vector<vector<int>> dp(N,vector<int>(N,-1));
    
    int i = 1;
    int j = N-1;
    
    
    return f(arr,i,j,dp);
    
    
}


// TABULATION --->

// See the flow and Reverse it..

// In memoization , 
// i -> 1 to n-1
// j -> n-1 to i+1

// In Tabulation -> 
// i -> n-1 to 1
// j -> i+1 to n-1

int matrixMultiplication(vector<int>& arr, int N) {

    vector<vector<int>> dp(N, vector<int>(N));

    // Initialize the diagonal elements of the DP table to 0
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for(int i = N - 1 ; i >= 1 ;i--){

        for(int j = i+1 ; j < N ;j++){

            int mini = INT_MAX;
    
            // partioning loop
            for(int k = i; k <= j-1; k++){
                
                int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                
                mini = min(mini,ans);
                
            }

            dp[i][j] = mini;

        }

    }

    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}