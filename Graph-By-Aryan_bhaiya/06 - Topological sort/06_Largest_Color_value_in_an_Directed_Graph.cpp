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



// A COMMON MISTAKE ---> DP + Graph

// Hum DP le lenge and DFS me backtrack krte samay dp me uss node ke liye uss path ka answer store kar lenge.. Next time yeah node se koi mangega
// to DP de denga ---> O(V + E)

// WRONG APPROACH --> Here we want max value, not value to add for the further path. Imagine aap kisi node se aa rhe ho and red color ka cnt = 3 
//                    hai.. Path me ek node encounter hua jiski DP me value hai.. Can we can take max between cnt and dp[i] --> NO
//                    Becz we dont know ki dp[i] ne kis color ke liye value store kar ke rakhi hai.. Agar usne 3 store kiya hai 3 blue color ke
//                    liye lekin uske path me 2 red color the jo min the, curr path me cnt = 3 hai red ki, wo dono add honge to cnt = 5 honga 
//                    max value 5 aayenga yeah path ka

// Option is to have 2d DP with each node with freq of 26 characters stored, but how will You determine that ki dp[i] was calculated before..
// It will be Complex to Do


// Aryan Bhai PDF link - 
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/solutions/3396205/image-explanation-simple-bfs-complete-intuition-c-java-python/


// 1. Here, we can try out all possible paths by doing DFS from each node , but there can be many path and it will give TLE 
// ( 10^5 nodes and 10^5 edges  )

// 2. We can observe that ki path of length 3 me color value 2 hai to path length 4 me color value >= 2 hi rhngi, decrease nhi hongi..
// So hum internal nodes ke path ko nullify kar dete -> to reduce the no. of paths. Max. length ke nodes ki path hi try krnge..
// 3. But here also overlapping is possible, PDF me diagram hai....
// 4. So, har baar path bnana by selecting source nodes and overlapping nodes se traverse krne se aacha hai ki Parent hi apni Color value apne 
// child me spread krde.
// 5. We have to ensure that ki jab child ke saare parents apni color value spread krde child me, uske baad hi child ko push kru queue me. Becz 
//    diff parent diff path ke honge, kiska color value jyada hai, how we can determine first ? Sabko try krna padega
// 6. Dependency, topological sort....


// SEE HOW THE CODE IS DONE...
// Har node pe a-z me se koi bhi color ho sakta hai... So Each node with 26 ka vector for colors...

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;

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

            for (int i = 0; i < 26; i++) {
                counts[v][i] =
                    max(counts[v][i],
                        counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
            }

            indegrees[v]--;

            if (indegrees[v] == 0) {
                zero_indegree.push(v);
            }

        }

    }

    return visited == n ? max_count : -1;
    
}

