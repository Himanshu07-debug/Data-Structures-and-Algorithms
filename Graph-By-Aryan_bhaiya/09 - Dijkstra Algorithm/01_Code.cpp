#include <bits/stdc++.h>
using namespace std;

// Using Normal Queue ------------------------------------------>>>

// will give answer, But too many unncessary nodes computation honge, becz min dist wale ke sath-sath jo min. nhi hai, wo bhi insert honge..

// Using Priority Queue ----------------------------------------->>>

// Have less no. of Unnecessary Operation..
// When the node dist gets updated, the previous pair of node with greater distance is not removed and updated one is added.. 
// So for this node whose dist where further updated, their computation will be unnecessary.. They are storing greater dist value than that of the
// min. updated dist, so wo apne childs ke dist[] values ko update nhi kar sakte...

// In PQ, (4, 3) , (2, 3)
// (2, 3) -> 3rd node ke childs 2 dist ke sath updated
// (4, 3) -> 3rd node ka this dist will not have any effect on the childs

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distTo(V, INT_MAX);

    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];

            if (dis + w < distTo[v])       
            // This condition is MOST imp, Add in Queue, only after this Condition check becz this is acting as Visited in Dijkstra Algo
            // Queue me add kiye outside the Condition block --> INFINITE (continously childs will be added)
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }

    return distTo;

}

// Using SET ------------------------------------------------->>>

// SET also works with some minor diff in Time, becz You have an extra logV operation of removing the Previous child of greater distance during 
// the updation...

// If You will see, this Code is More Efficient --> As You are not Keeping the Same vertex node > 1 in SET.

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){

    set<pair<int,int>> st; 

    vector<int> dist(V, 1e9); 
    
    st.insert({0, S}); 

    dist[S] = 0;
    
    while(!st.empty()) {

        auto it = *(st.begin()); 
        int node = it.second; 
        int dis = it.first; 
        st.erase(it); 
        
        for(auto it : adj[node]) {
            int adjNode = it[0]; 
            int edgW = it[1]; 
            
            if(dis + edgW < dist[adjNode]) {

                // erase if it was visited previously at a greater cost.
                if(dist[adjNode] != 1e9) 
                    st.erase({dist[adjNode], adjNode}); 
                    
                // If current distance is smaller, push it into the queue
                dist[adjNode] = dis + edgW; 
                st.insert({dist[adjNode], adjNode}); 
                }
        }
    }

    return dist; 

}


// TIME ---> O(E log V)  ==> PHOTO

// V^2 --> E  becz In worst case, every node will have (v - 1) edges i.e v * (v - 1) ==> No. of edges

// SPACE ---> O( E + V )
// in the Worst, saare edge store hue becz everytime updation was there, and vertex to store honge hi pure..



int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;

}