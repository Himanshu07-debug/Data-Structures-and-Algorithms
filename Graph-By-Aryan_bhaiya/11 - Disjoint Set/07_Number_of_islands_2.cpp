#include <bits/stdc++.h>
using namespace std;

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

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {

        vector<vector<int>> arr(n, vector<int>(m, 0));

        DisjointSet ds(n * m);

        int cnt = 0;

        vector<int> ans;
        
        unordered_set<int> st;

        vector<pair<int,int>> dir = {{0, -1} , {0, 1} , {1, 0} , {-1, 0}};

        for(auto xa : op){

            int i = xa[0] , j = xa[1];
            
            int curr = i*m + j;
            
            if(!st.count(curr)){
                set<int> s;

                arr[i][j] = 1;
                
                cnt++;
                
                for(pair<int,int> p : dir){
    
                    int x = i + p.first;
                    int y = j + p.second;
    
                    if(x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == 1){
    
                        int node = x*m + y;
    
                        int parent = ds.findUPar(node);
    
                        if(!s.count(parent)) cnt--;
    
                        s.insert(parent);
    
                        ds.unionBySize(curr, node);
    
                    }
    
                }

            }
            
            
            st.insert(curr);

            ans.push_back(cnt);

        }

        // for(int x : ans) cout << x << " ";

        // cout << endl;

        return ans;
       
    }

};
