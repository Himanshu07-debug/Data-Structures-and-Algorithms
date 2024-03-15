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

// The objective is to find the minimum number of hops. BFS is the ideal candidate for this question since it will provide the shortest path.

// At each moment, we have the option to take forward or backward move...
// But You cant take backward move twice in a row --> A flag variable to keep track of previous moves

// Think this as number line of x from 0 to 2000


// To avoid going to the same pos multiple times we will maintain a visited data-structure which will keep track of already visited positions. 
// Mark the forbidden positions as visited in vis array
// REMEMBER --> this is BFS visit more than once i.e same node pe aap backward or forward dono isase aa sakte ho, so visited me second parameter
//              flag to handle this


// IMP --> When to Terminate ???
// Backward is simple --> If the node backward move < 0  OR  prev move is backward

// FORWARD is the most Trickest part ---
// 






int minimumJumps(vector<int>& arr, int a, int b, int x) {

    queue<pair<int,int>> q;

    // forward max limit
    int len = 2000 + a + b;

    vector<vector<int>> vis(len + 1, vector<int>(2, 0));


    for(int x : arr){
        vis[x][0] = vis[x][1] = 1;     
    }

    q.push({0, 0});
    vis[0][0] = 1;

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

            if(f <= len && vis[f][0] == 0){
                q.push({f, 0});
                vis[f][0] = 1;
            }
 

            if( ba >= 0 && m != 1 && vis[ba][1] == 0){
                q.push({ba, 1});
                vis[ba][1] = 1;
            }

        }

        step++;

    }

    return -1;

}

// Optimizations --> You dont need whole len space ---> No. of valid states can be less 
//                  Use unordered set instead of len sized array. 

// TIP ------------->>
// Unordered set me pair<int,int> use nhi kar sakte...
// Then, You have to use set --> This will not be an optimization .. Cost logn time more
// In visited, we have 2 flag for each position --> backward and forward

// use 2 unordered set ==> Forward , backward ...
// Now the time and performance both Improve

// Remember this trick of transition from --> Visited with not using SET and using 2 hashset


int minimumJumps(vector<int>& arr, int a, int b, int x) {

    queue<pair<int,int>> q;

    // forward max limit
    int len = 2000 + a + b;

    unordered_set<int> forward, backward;

    for(int x : arr){  
        forward.insert(x);
        backward.insert(x);
    }

    q.push({0, 0});
    forward.insert(0);

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

            if(f <= len && !!forward.count(f)){
                q.push({f, 0});
                forward.insert(f);
            }  


            if( ba >= 0 && m != 1 && !backward.count(ba)){
                q.push({ba, 1});
                backward.insert(ba);
            }
            
            

        }

        step++;

    }

    return -1;

}