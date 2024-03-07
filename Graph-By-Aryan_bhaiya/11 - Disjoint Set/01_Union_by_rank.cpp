// Refer Graph Book --> Usme DSU ke notes hai

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{

    vector<int> rank, parent;

    public:

    DisjointSet(int n){
        rank.resize(n+1, 0);   // 1-based indexing of nodes [ this general template work for 0 -> n-1 ]
        parent.resize(n+1);

        // Initial Parent vector
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }

    }

    // Finding BOSS --> Ultimate Parent
    int findUltimatePar(int node){

        if(node == parent[node]) return;

        // Path compression is used here
        return parent[node] = findUltimatePar(parent[node]);

    }

    void unionByRank(int u, int v){

        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);

        // if ultimate parent are same --> They belong to same component
        if(ulp_u == ulp_v) return;

        // Connect to smaller one
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        // Same rank aaya to --> do rank++ in vector
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }


};

int main(){

    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Dynamic Graph --> Query ( 3 and 7 in same component )

    if(ds.findUltimatePar(3) == ds.findUltimatePar(7)) cout << "Same" << "\n";
    else cout << "Not Same" << "\n";

    ds.unionByRank(3, 7);

    if(ds.findUltimatePar(3) == ds.findUltimatePar(7)) cout << "Same" << "\n";
    else cout << "Not Same" << "\n";

    // DRY RUN in our notes

    return 0;

}

// TIME --> O(4 * alpha) == same as Constant time [ Derivation will not asked ]