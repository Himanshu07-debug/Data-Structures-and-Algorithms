#include <bits/stdc++.h>
using namespace std;

// If n is the length of the array , then each indx i, it will have string of size n denoting complete row of the ith row
// In the string of each indx row, s[j] represents the jth col 1*1 square of that row...

// Three operators are allowed to a one 1*1 square i.e a cell given in array ---> "\" , "/" , " "

// If "\" or "/" --> divides into 2 regions
// If " " --> do not divide

// Keyword --> no. of regions ---> DSU kar sakte hai kya ???

// How Graph can be related here ????

// See the example test cases --> In a single 1*1 square 
// If You make a slice ---> 2 regions. This regions can be represented by 2 distinct no.s .

// Problem if You represent a square with 2 no.s ???
// For forward slash, Aap numbering kar diye 1 and 2 . Agar aap forward ke jagah Backlash kronge to regions ko forward me jaise define kiye the
// waise isme nhi kar paonge... Agar kronge forward jaisa to regions Overlapp honge..
// We have to find a generic form for all operation.

// Solution --> Make both slash in a single 1*1 square --> 4 regions , No overlapping. Agar "/", then connect 0, 2 and 1, 3
//              Aur agar "\" , then connect 0,1 and 2, 3 . If " " --> Connect all 4 regions..

// MOST GENERIC WAY for all Operators in a Square ... 
// PHOTO in the folder

// Now for Other squares, unke sath bhi 1*1 square regions bna sakta hai ... For this we will see 4 directionally to the adjacnet of curr square.


// As we will number the regions, DSU will make the component connections a Cake walk

// Awesome DSU question ...

class DisjointSet {

    vector<int> parent, size;

public:
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




class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();

        DisjointSet ds(4*n*n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                // cell root no.
                int root = 4 * (i*n + j);  

                // within the square connection

                if(grid[i][j] == '/'){
                    ds.unionBySize(root, root + 1);
                    ds.unionBySize(root + 2, root + 3);
                }
                else if(grid[i][j] == ' '){
                    ds.unionBySize(root, root + 1);
                    ds.unionBySize(root, root + 2);
                    ds.unionBySize(root, root + 3);
                }
                else if(grid[i][j] == '\\'){    // dont take this as 2 character in a string, it is single character and mentioned in Q

                    ds.unionBySize(root, root + 2);
                    ds.unionBySize(root + 1, root + 3);

                }


                // Now its time for neighours connection

                if(i - 1 >= 0){

                    int upper_root = root - 4*n;
                    ds.unionBySize(root, upper_root + 3);

                }

                if(i + 1 < n){

                    int lower_root = root + 4*n;
                    ds.unionBySize(root + 3, lower_root);

                }

                if(j - 1 >= 0){

                    int left_root = root - 4;
                    ds.unionBySize(root + 1, left_root + 2);

                }

                if(j + 1 < n){

                    int right_root = root + 4;
                    ds.unionBySize(root + 2, right_root + 1);

                }
                

            }
        }
        
        int regions = 0;

        for(int i=0;i<4*n*n;i++){

            if(i ==  ds.findUPar(i)){
                regions++;
            }

        }

        return regions;
        
    }
};