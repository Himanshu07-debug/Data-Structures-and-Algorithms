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

int findJudge(int n, vector<vector<int>>& arr) {

    vector<int> ind(n+1, 0) , out(n+1, 0);

    for(auto x : arr){
        ind[x[1]]++;
        out[x[0]]++;
    } 

    for(int i=1;i<=n;i++){

        if(ind[i] == n-1 && out[i] == 0){
            return i;
        }

    }

    return -1;

}