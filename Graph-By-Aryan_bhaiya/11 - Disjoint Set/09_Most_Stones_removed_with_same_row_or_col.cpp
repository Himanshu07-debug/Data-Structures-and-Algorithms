#include <bits/stdc++.h>
using namespace std;

// For this Question ---> Explanation in Book notes

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
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;

        for(auto x : stones){
            maxRow = max(maxRow, x[0]);
            maxCol = max(maxCol, x[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        // To store the cells with 1 value, We can't create the whole matrix due to constraint
        map<int,int> mp;

        for(auto x : stones){

            int row = x[0];
            int col = x[1] + maxRow + 1;

            ds.unionBySize(row, col);

            mp[row] = 1;
            mp[col] = 1;

        }

        int cnt = 0;

        for(auto [a, b] : mp){

            if(ds.findUPar(a) == a){
                cnt++;
            }

        }

        return (n - cnt);
        
    }
};