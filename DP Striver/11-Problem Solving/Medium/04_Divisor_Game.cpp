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

// TIME --> O(n * sqrt(n))

// if 1 <= n <= 10^6 ... 
// then above will be TLE
// then precomputing divisors for each i in a vector will be a good option....
// Seive and take a array of vector like graph where node will be number and list will be all divisors...

// it will not give TLE 
// max no. of divisors of n can be n only
// maxN = 10^6 ,  10^6 divisor 
// so sum of n/(all divisors i) 
// n/i1 + n/i2 + ..... ------------------->> n * (1/i1 + 1/i2 + .................. + 1/in)  ==> logn




// How to get to some Patterns ------------------------->>>

// Whatever was your Recursive DP code, run it for some starting 100 numbers and observe the answer --> JUST to check ==> is there any Pattern ??

bool diviorGame(int n){

    for(int i=1;i < 100;i++){
        cout << i << " " << help(i) << endl;
    }

    // if you find pattern , verify

    for(int i=1;i<100;i++){
        assert(help(i) == (1 - (i%2)));          // for even --> 1 is coming and odd --> 0
    }

    // if assert is true, then there will be no print in the output... DONE
    // otherwise assert is failing

}


// Best explanation to understand ---> 

// LINK --->  https://leetcode.com/problems/divisor-game/solutions/382233/solution-in-python-3-with-detailed-proof/

bool divisorGame(int n) {

    return (n % 2 == 0);

}




