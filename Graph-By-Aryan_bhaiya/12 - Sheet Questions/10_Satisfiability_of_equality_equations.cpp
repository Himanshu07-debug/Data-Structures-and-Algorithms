#include <bits/stdc++.h>
using namespace std;

// we have to check for conflict i.e a == b aaye to koi bhi expression se a != b na aaye...
// Conflict hai ki nhi --> Query type in faster time --> DSU ,  We can create a Component of one and then check by other to see the conflict

// We will make a Component of Equality varaiables first .. 
// Then I we will go to each non-equality equation, if we find them in same component, we will return false..

// Why first Equality, then in another loop non-equality ??
// becz it can be possible ki array ki ordering me phle a != b aaye then a == b
// first time wale non-equality tk a and b same component me nhi aaye the

// Why component of equality , non-equlaity ka kyu nhi ??
// In equality, we have no uncertaintity
// But in non-equlality we have --> we cant make component of it
// Example -> a != b && b != c           ---> Here a, b, c will be in the same component which means a != b != c 
//                                       ---> but it can be possible ki a == c ho jaaye [ 3 != 2  && 2 != 3  , a & c are same ]

class DisjointSet {

    vector<int> parent, size;

public:
    DisjointSet(int n) {

        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);

    }


    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    bool equationsPossible(vector<string>& eq) {

        DisjointSet ds(26);

        for(string s : eq){

            int x = s[0] - 'a' , y = s[3] - 'a';

            if(s[1] == '='){

                ds.unionBySize(x, y);

            }

        }

        for(string s : eq){

            int x = s[0] - 'a' , y = s[3] - 'a';

            if(s[1] == '!'){

                int ulx = ds.findUPar(x) , uly = ds.findUPar(y);

                if(ulx == uly) return false;

            }

        }

        return true;
        
    }
};

// Other similar Problems --> 
// 1. Smallest String With Swaps
// 2. Number of Good Paths
// 3. Number of Islands
// 4. Longest Consecutive Sequence
// 5. Number of Provinces
// 6. Redundant Connection
// 7. Max Area of Island
// 8. Is Graph Bipartite?