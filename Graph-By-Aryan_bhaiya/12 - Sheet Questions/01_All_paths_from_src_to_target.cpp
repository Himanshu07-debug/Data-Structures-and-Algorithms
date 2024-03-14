#include <bits/stdc++.h>
using namespace std;

void dfs(int src, int n, vector<int> &path, vector<vector<int>>& ans , vector<vector<int>>& gr) {

    path.push_back(src);

    if(src == n-1){
        ans.push_back(path);
    }

    for (auto child : gr[src]) {

        // child not visited
        dfs(child, n, path, ans, gr);
        
    }

    path.pop_back();

}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& gr) {
        
    int n = gr.size();

    vector<vector<int>> ans;

    vector<int> path;

    dfs(0, n, path, ans, gr);

    // for(auto x : ans){
    //     for(int y : x){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    return ans;

}