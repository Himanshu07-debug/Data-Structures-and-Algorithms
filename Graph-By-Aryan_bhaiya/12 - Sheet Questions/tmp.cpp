#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Min no. of Jumps ---> BFS

// Facing Problem in how to terminate ??
// use visited and all condition possible
// x ranges from 0 to 2000

// Also facing problem -->
// x = 2000 , forbidden --> [1998] , a = 1999 , b = 2000
// Ans --> 3998
// val is allowed to go beyond 2000 for getting the answer


int minimumJumps(vector<int>& arr, int a, int b, int x) {

    unordered_set<int> st;
        
    for(int x: arr) st.insert(x);

    queue<pair<int,int>> q;

    vector<int> vis(2001, 0);

    q.push({0, 0});
    vis[0] = 1;

    int step = 0;

    while(!q.empty()){

        int z = q.size();

        for(int i=0;i<z;i++){

            int val = q.front().first;
            int m = q.front().second;
            q.pop();

            if(val == x) return step;

            int f = val + a;
            int ba = val - b;

            if(!st.count(f) && f <= 2000 && vis[f] == 0){
                q.push({f, 0});
                vis[f] = 1;
            } 

            if(!st.count(ba) && ba >= 0 && m != 1 && vis[ba] == 0){
                q.push({ba, 1});
                vis[ba] = 1;
            }

        }

        step++;

    }

    return -1;

}