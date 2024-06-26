// Given an expression, A, with operands and operators (OR, AND, XOR), in how many ways can you evaluate the expression to be true, by 
// grouping it in different ways?

// Input: expression = “T|T&F”
// Output: 1
// Explanation: The only way to get the resuLt as true is:
// (T) | (T&F) = T|F = T 


// LOGIC ------------------------------------------->>>

// Diff ways to solve expression ---> T | T & F ===> (T) | (T & F)  ,, (T | T) & (F)

// This is similar to MCM type of Question, Whenever you get AND, OR, XOR --> You can make PaRTition

// The only Hack here is that To think for each Symbol , What are the Possible values of Left and Right haLF are Acceptable ..

// OBSERVE Carefully, aapko sirf true ka hi cnt nhi sochna hai partition ke left and right sub parts ka.. You should also know about the false
// resulting ways of the both sides... as while solving expressions results... False values can also be used... 
// ex --> OR yields true.. even if one side is false... 

// For ex -> We want true ( I am Lazy, I will only worry about the my work & rest Recursion will do )

// if there are total x1 + y1 diff ways of partitions in the left part, out of them ->
// Let I have x1 no. of ways to get true and y1 no. of ways to get False in the left paRT

// if there are total x2 + y2 diff ways of partitions in the right part, out of them ->
// Let x2 no. of ways to get true and y2 no. of ways to get False in Right paRT...

// If symbol is AND -->
// We want true --> So Dono haLF se True chahiye, So total no. of ways --> x1 * x2

// If OR --> x1 * x2  +  x1 * y2  +  x2 * y1


// So most Important TIP of this problem --> keep track of count of both values (True and false) for each partition ( each subparts )

// BASE CASE ---> 
// i > j

// Single element --> i == j 
// if i want true and get the exp[i] as true... return 1 or 0
// vice versa for false

#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int fun(int i, int j, int isTrue, string &exp){

    if(i > j) return 0;

    if(i == j){

        if(isTrue == 1) return (exp[i] == 'T');
        else return (exp[i] == 'F');

    } 

    long long ways = 0;

    for(int k = i + 1; k <= j-1 ; k += 2){   // Symbols will be at each 2 step of Expression

        long long LT = fun(i, k - 1, 1, exp);
        long long LF = fun(i, k - 1, 0, exp);

        long long RT = fun(k + 1, j, 1, exp);
        long long RF = fun(k + 1, j, 0, exp);

        if (exp[k] == '&') {

            if (isTrue) ways = (ways + (LT * RT) % mod) % mod;
            else ways = (ways + (LF * RT) % mod + (LT * RF) % mod + (LF * RF) % mod) % mod;

        }
        else if (exp[k] == '|') {

            if (isTrue) ways = (ways + (LF * RT) % mod + (LT * RF) % mod + (LT * RT) % mod) % mod;
            else ways = (ways + (LF * RF) % mod) % mod;

        }
        else {  

            if (isTrue) ways = (ways + (LF * RT) % mod + (LT * RF) % mod) % mod;
            else ways = (ways + (LF * RF) % mod + (LT * RT) % mod) % mod;

        }

    }

    return ways;

}


int evaluateExp(string &exp) {

    int n = exp.size();

    return fun(0, n - 1, 1, exp);  // StaRT evaluation with isTrue set to true.

}


// RECURSION ---> Exponential

// MEMOIZATION --> 3 changing Parameters --> O(n * n * 2 * n) --> O(n ^ 3) TIME  &&  O(n * n) + O(n) [ Stack Space ]

// dp[i][j][2]


// TABULATION



