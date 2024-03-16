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

int firstUniqChar(string s) {

    int n = s.size();

    int cnt[256] = {0};

    int indx = -1;

    for(int i=n-1;i>=0;i--){

        if(cnt[s[i]] == 0){
            indx = i;
        }
        cnt[s[i]]++;

    }

    if(indx != -1 && cnt[s[indx]] == 1) return indx;

    return indx; 
        
}