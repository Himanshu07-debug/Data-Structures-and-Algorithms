#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;

// An extension of LIS
// Subsequence -> so can't sort

// For any indx i , To each prev jth index, I will ask the question that they have some length for the given diff, If yes, I will add 1 to that
// value,
// Otherwise, I will Intialize the Subsequence with given diff at indx i so that It can be used further..


// diff can be -ve --> So use Map to store diff : len as pair

// NAIVE --->

int longestArithSeqLength(vector<int>& arr) {

    int n = arr.size();

    vector<unordered_map<int,int>> dp(n);

    int mx = 0;

    for(int i=0;i<n;i++){

        for(int j=0; j < i ;j++){

            int diff = arr[i] - arr[j];

            if(dp[j][diff] != 0){
                dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
            }
            else{
                dp[i][diff] = 2;    // 2 length subsequence for the curr diff
            }

            if(dp[i][diff] > mx) mx = dp[i][diff];

        }

    }

    return mx;

}

// Optimization -->

// Do not use unordered_map..
// max diff can be 500 (0 and 500)
// min diff can be -500 ( 500 and 0 )

// Shifting of diff values by 500

// Now -500 -> 0 , 0 -> 500 ,  500 --> 1000

// diff = arr[i] - arr[j] + 500

int longestArithSeqLength(vector<int>& arr) {

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(1001, 0));

    int mx = 0;

    for(int i=0;i<n;i++){

        for(int j=0; j < i ;j++){

            int diff = arr[i] - arr[j];

            if(dp[j][diff] != 0){
                dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
            }
            else{
                dp[i][diff] = 2;    // 2 length subsequence for the curr diff
            }

            if(dp[i][diff] > mx) mx = dp[i][diff];

        }

    }

    return mx;

}


// If difference given --> 

// a - b = diff
// b = a - diff
// i.e for any arr[i] -> I have to ask that is there arr[i] - diff exist at the back indexes.  


int longestSubsequence(vector<int>& arr, int difference) {

    int n = arr.size();

    unordered_map<int,int> mp;

    int mx = 1;  // 1 can always be an answer [ A subseq with no adj elements ]

    for(int i=0;i<n;i++){

        int b = arr[i] - difference;

        if(mp.count(b)){
            mp[arr[i]] = 1 + mp[b];
        }
        else{
            mp[arr[i]] = 1;
        }

        mx = max(mx, mp[arr[i]]);

    }

    return mx;
        
}