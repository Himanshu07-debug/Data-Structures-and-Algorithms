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

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> arr, int id) {
        
    int n = arr.size();

    unordered_map<int, Employee*> gr;

    for(auto e : arr){
        gr[e->id] = e;
    }

    queue<int> q;
    q.push(id);

    vector<int> vis(2001, 0);
    vis[id] = 1;

    int ans = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        Employee* e = gr[x];

        ans += e->importance;

        for(int y : e->subordinates){
            if(vis[y] == 0){
                vis[y] = 1;
                q.push(y);
            }
        }

    }

    return ans;

}