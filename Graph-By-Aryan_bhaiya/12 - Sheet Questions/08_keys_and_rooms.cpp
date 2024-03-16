#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& arr) {

    int n = arr.size();

    vector<int> vis(n, 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int cnt = 0;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        cnt++;

        for(int x : arr[node]){

            if(vis[x] == 0){
                q.push(x);
                vis[x] = 1;
            }

        }

    }

    return (cnt == n);

    // No need of cnt --> vis me jaake dekh sakte ho sab visit hue kya
    // Just a Traversal Q.s --> DFS lgana optimal rhta

}