#include<bits/stdc++.h>
using namespace std;

// n == 1 will always be a Valid factor

// Recursive --------------------------------->>

bool help(int n){

    if(n == 1) return false;

    for(int i=1;i<n;i++){

        if(n % i == 0){

            bool other = help(n - i);

            if(other == false) return true;

        }

    }

    return false;

}

bool divisorGame(int n) {

    return help(n);

}

// TIME --> O(n^n) * n


// DP -------------------------------->>

// See at n = 8, you will get Overlapping subproblem

bool help(int n, vector<int> &dp){

    if(n == 1) return false;

    if(dp[n] != -1) return dp[n];

    for(int i=1;i<n;i++){

        if(n % i == 0){

            bool other = help(n - i, dp);

            if(other == false) return dp[n] = true;

        }

    }

    return dp[n] = false;

}

bool divisorGame(int n) {

    vector<int> dp(n + 1, -1);

    return help(n, dp);

}

// TIME --> O(n^2)


// OPTIMIZATION ---> 
// For Factors of n , we only have to run for sqrt(n)

bool help(int n, vector<int> &dp){

    if(n == 1) return false;

    if(dp[n] != -1) return dp[n];

    for(int i=1;i*i<=n;i++){

        if(n % i == 0){

            bool other1 = help(n - i, dp);

            bool other2 = true;

            if(i != 1){
                other2 = help(n - n/i, dp);
            } 

            if(other1 == false || other2 == false) return dp[n] = true;

        }

    }

    return dp[n] = false;

}




// Best explanation to understand ---> 

// LINK --->  https://leetcode.com/problems/divisor-game/solutions/382233/solution-in-python-3-with-detailed-proof/

bool divisorGame(int n) {

    return (n % 2 == 0);

}