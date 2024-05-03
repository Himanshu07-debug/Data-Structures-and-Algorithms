#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// struct node{

//     int data;
//     node* left;
//     node* right;

//     node(int x){
//         data = x;
//         left = NULL;
//         right = NULL;
//     }

// };

// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

class Solution {
public:

    int help(int i, int n, string &s, vector<int> &dp){

        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int x = help(i+1, n, s, dp);

        int y = 0;

        if(i + 1 < n){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');

            if(num <= 26) y = help(i+2, n, s, dp);
        }

        return dp[i] = x + y;

    }

    int numDecodings(string s) {

        int n = s.size();
        vector<int> dp(n, -1);

        return help(0, n, s, dp);
        
    }
};

