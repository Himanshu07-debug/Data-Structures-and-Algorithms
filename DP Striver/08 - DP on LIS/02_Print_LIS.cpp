#include<bits/stdc++.h>
using namespace std;

// Finding the Length --

// NOTE - OPTIMAL SOLUTION for Longest LIS

// While Traversing the array, hum max LIS nikalenge ending at current indx 
// For each indx, uske saare prev me traverse krnge and jo max length honga --> usme +1 


int longest(vector<int> arr, int n) {

    int mx = 0;

    vector<int> dp(n, 1);        // At every Indx, LIS will be of atleast 1 length

    for(int i=0;i<n;i++){

        for(int prev = 0 ; prev < i ; prev++){

            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], dp[prev] + 1);
            }

        }

        mx = max(mx, dp[i]);

    }
	
    return mx;
}

// TIME -> O(n * n)
// SPACE -> O(n)


// Printing LIS ---------------------->>

// Using Backtracking technique...

// At each indx, putting the Prev indx with max length value, If it do not exist, put the current indx value, So that we can use it as Breaking
// condition

vector<int> printingLIS(vector<int> arr, int n) {

    int mx = 0;

    vector<int> dp(n, 1);    

    vector<int> indx(n);

    int lastIndx = 0;

    for(int i=0;i<n;i++){

        indx[i] = i;

        for(int prev = 0 ; prev < i ; prev++){

            if(arr[prev] < arr[i]){
                
                if(dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    indx[i] = prev;
                }

            }

        }

        if(dp[i] > mx){
            mx = dp[i];
            lastIndx = i;
        }

    }

    vector<int> lis;

    lis.push_back(arr[lastIndx]);

    while(indx[lastIndx] != lastIndx){

        lastIndx = indx[lastIndx];

        lis.push_back(arr[lastIndx]);

    }

    reverse(lis.begin(), lis.end());

    return lis;
    
}


// NOTE --> Here there is Still O(n * n) Time.. But this is the code for Printing LIS



