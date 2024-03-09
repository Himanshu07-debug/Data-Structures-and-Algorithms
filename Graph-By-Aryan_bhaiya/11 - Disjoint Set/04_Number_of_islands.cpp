// By DSU

// No. of diff Boses possible in parent array, wahi answer honga..
// Inorder to find distinct parents from parent array --> SET 
// More better --> if( node == parent[node] )  ---> node khud ka hi BOSS hai --> ULTIMATE PARENT

#include <bits/stdc++.h>
using namespace std;

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

int main() {

    int n = 3;

    vector<vector<int>> gr = { {1, 0, 1} , {0, 1, 0} , {1, 0, 1} };

    DisjointSet ds(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(gr[i][j] == 1){
                ds.unionBySize(i, j);
            }

        }
    }

    int ans = 0;

    // No. of islands
    for(int i=0;i<n;i++){
        if(ds.parent[i] == i)  ans++;
    }

    cout << ans << endl;
    
    return 0;
    
}