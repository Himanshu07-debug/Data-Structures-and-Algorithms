// You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1, an array edges where 
// edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti. You are also given an
//  integer signalSpeed.

// Two servers a and b are connectable through a server c if:
// a < b, a != c and b != c.
// The distance from c to a is divisible by signalSpeed.
// The distance from c to b is divisible by signalSpeed.
// The path from c to b and the path from c to a do not share any edges.
// Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.

// Input: edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
// Output: [0,4,6,6,4,0]
// Explanation: Since signalSpeed is 1, count[c] is equal to the number of pairs of paths that start at c and do not share any edges.

// 1 <= n <= 2000

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// LOGIC ------------------------------------->>>

// We have to build the cnt array for each index i.e for node 0 to n - 1

// This means we will considered each node as a server and will see the valid Connectable pairs for it...

// We have to build a Graph
// What we can do, we will calculate the distance of all nodes from the current ith server.. 

// O(n) ==> for all nodes as a server --> O(n ^ 2) [ chalta, see constraint ] 

// If the distance is divisible by signalSpeed, This are the Good nodes for current ith server thatn is potential to form a pair

// This is very clear that ki a & b ko ith server ke different subtree me rhna honga.. becz then only i will act as a connectable kyuki path
// ke beech me wo hai....

// Hum ith server ke distinct subtress me kitne count of valid nodes hai .. uska cnt rkhnge...
// Now simple mathemathics to get the no. of pairs they can form ---> 
// Suppose 1st subtree me 2, 2nd me 3 , 3rd me 4
// So , (2*3  +  2*4) + ( 3*2 + 3*4 ) + ( 4*2 + 4*3 )
// In this cnt, if (1, 5) was considered, (5, 1) will also considered...
// We have to remove them ---> total cnt / 2

// This will take O(n^2) --> for each one cnt, go to all other cnt

// We can simplify it --->
// For 1st subtree --> 2 * 3   +  2 * 4 -------->  2 * (3 + 4)
// for 2nd subtree --> 3 * 2   +  3 * 4 -------->  3 * (2 + 4)
// for 3nd subtree --> 4 * 2   +  4 * 3 -------->  4 * (2 + 3)

// Observe for each subtree, You are taking sum of all cnts of subtrees except the current subtree...
// for a subtree --> cnt * (sum - cnt)     ---> O(n)



// In Contest, when common graph is required is anywhere in code..
// Use graph in Global varaibles
unordered_map<int, vector<pair<int,int>>> gr;
int cnt = 0 , speed;

void dfs(int src, int dis, vector<int> &vis){

    if(dis % speed == 0) cnt++;

    vis[src] = 1;

    for(auto [a, b] : gr[src]){

        if(vis[a] == 0){
            dfs(a, dis + b, vis);
        }

    }

}


vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss) {

    int n = edges.size() + 1;

    speed = ss;

    for(auto x : edges){
        gr[x[0]].push_back({x[1], x[2]});
        gr[x[1]].push_back({x[0], x[2]});

    }

    vector<int> ans(n);

    for(int i = 0; i < n; i++){

        int sum = 0;
        vector<int> tmp;
        vector<int> vis(n, 0);
        vis[i] = 1;

        for(auto [a, b] : gr[i]){

            cnt = 0;

            // You have to cnt of valid nodes present in the subtree, so call from children as src in DFS
            dfs(a, b, vis);

            sum += cnt;
            tmp.push_back(cnt);

        }

        for(auto x : tmp) ans[i] += (x * (sum - x));

        ans[i] /= 2;

    }

    return ans;
        
}




