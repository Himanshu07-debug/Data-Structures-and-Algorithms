#include<bits/stdc++.h>
using namespace std;

// NAIVE ----------------->>

// Each Interval ke liye tab tk iterate krnge jab tak uske overlapping non visited pairs milenge

bool check(int st, int en, vector<int> arr){

    if(st > arr[1] || en < arr[0]){
        return false;
    }

    return true;

}

vector<vector<int>> merge(vector<vector<int>>& arr) {
        
    int n = arr.size();

    vector<bool> visited(n, false);

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){

        if(visited[i]) continue;

        int st = arr[i][0];
        int en = arr[i][1];

        visited[i] = true;

        while(true){

            int cnt = 0;

            for(int j = 0 ;j < n;j++){

                if(visited[j] == false && check(st, en, arr[j]) ){

                    visited[j] = true;
                    cnt++;

                    st = min(st, arr[j][0]);
                    en = max(en, arr[j][1]);

                }

            }

            if(cnt == 0) break;

        }

        ans.push_back({st, en});

    }

    sort(ans.begin(), ans.end());

    return ans;



}