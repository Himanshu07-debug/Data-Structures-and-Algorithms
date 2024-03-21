#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;
const long long NINF = LLONG_MIN;

int fun(int i, int prev, vector<pair<int,int>> &arr, int n, vector<vector<int>> &dp){

    if(i < 0) return 0;

    if(dp[i][prev] != INT_MAX){
        return dp[i][prev];
    }

    int pick = 0;

    if(prev == n || arr[i].first == arr[prev].first || arr[i].second < arr[prev].second){
        pick = arr[i].second + fun(i-1, i, arr, n, dp);
    }

    int skip = fun(i-1, prev, arr,n, dp);

    return dp[i][prev] = max(pick, skip);

}

int bestTeamScore(vector<int>& scores, vector<int>& ages) {

    vector<pair<int,int>> arr;

    for(int i=0;i<scores.size();i++){

        arr.push_back({ages[i], scores[i]});

    }

    int n = ages.size();

    vector<vector<int>> dp(n, vector<int>(n+1, INT_MAX));

    sort(arr.begin(), arr.end());

    return fun(n-1, n, arr, n, dp);

}