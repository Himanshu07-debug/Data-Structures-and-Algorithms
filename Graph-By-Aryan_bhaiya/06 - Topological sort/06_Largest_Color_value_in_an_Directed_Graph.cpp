#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;

// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). 
// You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 
// for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.

// n == colors.length
// m == edges.length
// 1 <= n <= 10^5
// 0 <= m <= 10^5

// LINK -> https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/


// LOGIC -------------------->>


// For any path, agar kisi color ki value 2 hai, then aage path me uss color ki value >= 2 hongi .. less nhi ho skti

// We will use this concept and will explore the longest path.. Baaki short-short path ka bhi results rkhe rhnge i.e keeping track of all paths

// DFS ------------------------------->>

// So agar kisi src se multiple path nikal rhe hai.. To uske cnt array me jo values update hue honge wo max color value freq honge jo usase nikle
// hue multiple path ke honge... 
// Now we have to select the maximum freq wla color  ---> this shows humne wo path choose kiye jha se yeah wla max freq aa rha hai ..
// This is the max color value for the src...

// In DFS we are letting our whole childs to propogate the src cnt array and then src array khud ko update krke max return krta hai

// Leetcode pe chal gya code --> Time --> O( V + E )

// There is possibility ki code na chale --> becz if there are many paths .. For very tight constraint

// TOPO is Efficient --> First tell DFS , then TOPO


int dfs(int src, vector<int> &vis, vector<int> &pathVisited, vector<vector<int>> &graph, vector<vector<int>> &cnt, string &colors){

    vis[src] = 1;
    pathVisited[src] = 1;

    for(int v : graph[src]){

        if(!vis[v]){
            if(dfs(v, vis, pathVisited, graph, cnt, colors) == INT_MAX){
                return INT_MAX;
            }

        }
        else if(pathVisited[v] == 1) return INT_MAX;

        // MISTAKE --------------->>

        // I was writing this for loop in the !vis[v] scope i.e agar cycle nhi aaya to child propogate krnge their cnt array to parent
        // This was mistake becz agar koi dursa path aa rha hai wo koi visited node pe jaata hai to we want ki visited wla DFS aage na badhaye,
        // apna cnt array propogate krde src ko, but uss scope me likhne ke wajah se sirf non-visited wle childs propogate kar rhe the value
        for(int i=0;i<26;i++){

            cnt[src][i] = max(cnt[src][i] , cnt[v][i]);

        }

    }

    pathVisited[src] = 0;

    cnt[src][colors[src] - 'a']++;

    int mx = *max_element(cnt[src].begin(), cnt[src].end());

    return mx;

}


int largestPathValue(string colors, vector<vector<int>>& edges) {

    int n = colors.size();

    vector<vector<int>> graph(n, vector<int>());

    for (vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }    

    vector<int> vis(n, 0) , pathVisited(n, 0);

    vector<vector<int>> cnt(n, vector<int>(26, 0));

    int res = 0;

    for(int i=0;i<n && res != INT_MAX ; i++){

        if(vis[i] == 0){
            res = max(res, dfs(i, vis, pathVisited, graph, cnt, colors));
        }
        else{
            int mx = *max_element(cnt[i].begin(), cnt[i].end());
            res = max(res, mx);
        }

    }

    if(res == INT_MAX) return -1;
    
    return res;


}

// TOPOLOGICAL SORT --------------------------------------->>

// Normal behaviour of DFS ki phle all childs then parent propogation can be reverted as in BFS..

// child ko jab saare parents propogate kar denge apni cnt values then child queue me aayenga ---> TOPO...

// See PDF 

// Aryan Bhai PDF link - 
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/solutions/3396205/image-explanation-simple-bfs-complete-intuition-c-java-python/


int largestPathValue(string colors, vector<vector<int>>& edges) {

    int n = colors.size();
    vector<int> indegrees(n, 0);

    vector<vector<int>> graph(n, vector<int>());

    for (vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        indegrees[edge[1]]++;
    }

    queue<int> zero_indegree;

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            zero_indegree.push(i);
        }
    }

    vector<vector<int>> counts(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        counts[i][colors[i] - 'a']++;
    }

    int max_count = 0;

    int visited = 0;

    while (!zero_indegree.empty()) {

        int u = zero_indegree.front();
        zero_indegree.pop();

        max_count = max(max_count,*max_element(counts[u].begin(), counts[u].end()));

        visited++;

        for (int v : graph[u]) {

            char color = colors[v];

            for(int i=0;i<26;i++){

                if(i == color - 'a') counts[v][i] = max(counts[v][i] , counts[u][i] + 1);
                else counts[v][i] = max(counts[v][i] , counts[u][i]);

            }

            indegrees[v]--;

            if (indegrees[v] == 0) {
                zero_indegree.push(v);
            }

        }

    }

    return visited == n ? max_count : -1;
    
}



