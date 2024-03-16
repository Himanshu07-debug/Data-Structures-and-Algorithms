#include <bits/stdc++.h>
using namespace std;

// Observe , all possible paths starting from a node are going to end at some terminal node unless there exists a cycle and the paths
// return back to themselves.
// so we can use Concept of "Cycles in Directed Graph"

// In a DFS path, first we go at depth, then while backtracking, we will add nodes if no cycles detected...
// A safe node is one whose all path ends at terminal node or at some safe node.. How this is ensured ??
// Terminal node pe sure hai ki outdegree 0 hai becz agar child hote and unvisited hote to unke pass jaata call OR agar child visited hote to,
// cycle detect hota ..
// There is one more case --> vis[child] = true and pathVis[child] = false .. Cycle detect nhi hua but curr node ko terminal nhi kah sakte usase,
// edge nikla hai , but it is Safe node as it will be ending at some terminal node...

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    // traverse for adjacent nodes
    for (auto it : adj[node])
    {
        // when the node is not visited
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, check) == true)
            {
                check[node] = 0;
                return true;
            }
        }
        // if the node has been previously visited but it has to be visited on the same path
        else if (pathVis[it])
        {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}


vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
            safeNodes.push_back(i);
    }
    return safeNodes;
}


// TOPO ---------------------------------------------------------------->>>

// Changing the Graph connection...
// terminal nodes ka indegree 0 ho jayega... Topo Sort

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{

    int n = graph.size();

    vector<int> in(n);
    vector<int> gr[n];

    for (int i = 0; i < n; i++)
    {
        for (int x : graph[i])
        {
            gr[x].push_back(i);
            in[i]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }

    vector<int> tSort;

    while (!q.empty())
    {

        int x = q.front();
        q.pop();

        tSort.push_back(x);

        for (int y : gr[x])
        {

            in[y]--;
            if (in[y] == 0)
                q.push(y);
        }
    }

    return tSort;
}