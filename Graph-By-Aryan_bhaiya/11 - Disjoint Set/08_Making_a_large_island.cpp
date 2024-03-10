#include <bits/stdc++.h>
using namespace std;

// LOGIC ----------------------->>

// Here, first we will try to represent the whole matrix cells as distinct numbers using numbering from 0 to n*n - 1

// We will prepare DSU now. 
// If a cell ke liye adjacnet negh me koi bhi 1 mile, to negh and cell ek island me hai and unke beech me edge honga, So we will consider edge 
// between them and will make DSU

// Once the Components making is done....

// Ab apko every 0 ko 1 krke check krna honga ki kon max. de rha hai size.
// Hum 0 ko sahi me 1 nhi krnge becz this will distort the DSU.. Hum revert nhi kar payenge changes jo current 0 se honge for the checking of 
// other further 0's

// We will assume ki 0 wale cell me 1 kar diye.. We will ask for Bosses of Adjacent cells kyuki wahi size array me whole component ka size rkhte 
// hai... Also be attentive , Same Boss ka size multiple baar add na hoye, iska dhyan rkhna ( It might be possible that ki 0 ke 2 negh same 
// component ke ho )

class DisjointSet {

public:
    vector<int> parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n*n);

        vector<pair<int,int>> dir = {{-1, 0}, {1, 0} , {0, 1}, {0, -1}};

        bool allOnes = true;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){

                    int v = i*n + j;

                    for(auto [a, b] : dir){

                        int x = i + a, y = j + b;

                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1){

                            int val = x*n + y;

                            ds.unionBySize(v, val);

                        }

                    }

                }
                else allOnes = false;

            }
        }

        if(allOnes) return n*n;

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0){

                    unordered_set<int> s;
                    int len = 0;

                    for(auto [a, b] : dir){

                        int x = i + a, y = j + b;

                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1){

                            int val = x*n + y;

                            int p = ds.findUPar(val);

                            if(!s.count(p)) len += ds.size[p];

                            s.insert(p);

                        }

                    }

                    mx = max(mx, len + 1);

                }

            }
        }

        return mx;
        
    }
};