#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void dfs(int i, int j, int n, int m, vector<vector<int>> &res, vector<vector<int>> &vis){

        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || res[i][j] == 0) return;

        vis[i][j] = 1;

        dfs(i-1, j, n, m, res, vis);
        dfs(i+1, j, n, m, res, vis);
        dfs(i, j-1, n, m, res, vis);
        dfs(i, j+1, n, m, res, vis);

    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &arr) {

        vector<vector<int>> res(n, vector<int> (m, 0));

        vector<int> ans;

        for(int i=0;i<arr.size();i++){

            int cnt = 0;

            int x = arr[i][0] , y = arr[i][1];

            res[x][y] = 1;
            vector<vector<int>> vis(n, vector<int> (m, 0));

            for(int j=0;j<n;j++){
                for(int k = 0; k< n;k++){

                    if(res[j][k] == 1 && vis[j][k] == 0){
                        dfs(j, k, n, m, res, vis);
                        cnt++;
                    }

                }
            }

            ans.push_back(cnt);

        }

    }
};