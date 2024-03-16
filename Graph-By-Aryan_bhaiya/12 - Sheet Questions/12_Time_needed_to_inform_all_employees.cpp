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

int numOfMinutes(int n, int head, vector<int>& arr, vector<int>& time) {

    vector<int> gr[n];

    for(int i=0;i<n;i++){
        if(i != head){
            gr[arr[i]].push_back(i);
        }
    }

    int ans = 0;

    queue<int> q;
    q.push(head);
    vector<int> vis(n, 0);
    vis[head] = 0;

    while(!q.empty()){

        int z = q.size();
        int mx = 0;

        for(int i=0;i<z;i++){

            int id = q.front();
            q.pop();

            mx = max(mx, time[id]);

            for(int x : gr[id]){

                if(vis[x] == 0){
                    vis[x] = 1;
                    q.push(x);
                }

            }

        }

        ans += mx;

    }

    return ans;
        
}