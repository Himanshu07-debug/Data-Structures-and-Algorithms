#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// We will go to each Island --> Apply BFS to check border element hai kya usme ---> If YES, No Updation...

// TIME --> O(n * m * 4) [ BFS ] + O(n * m) [ Cells array will store at max n*m elements overall ]

// MAKE IT MORE SIMPLE ------------------------------------------------------->
// Boundary wale 'O' se nikla hua island always update nhi honga. Apply DFS in them... Jo visited aaye wo UPDATE nhi honge

// 1. Use a Visited array
// 2. first row, last row, first col, last col me jha pe 'O' & vis == 0 , Apply DFS (smaller code)
// 3. Those which remain unVisited --> make them 'X'

void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis, int n, int m ){


    vector<pair<int,int>> dir = {{-1, 0} , {1, 0} , {0, -1} , {0, 1}};

    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    bool border = false;
    vector<pair<int,int>> cells;

    while(!q.empty()){

        int i1 = q.front().first;
        int j1 = q.front().second;

        q.pop();

        if(i1 == 0 || j1 == 0 || i1 == n-1 || j1 == m-1) border = true;

        cells.push_back({i1, j1});

        for(auto [a, b] : dir){

            int x = i1 + a , y = j1 + b;
            
            if(x >= 0 && y >= 0 && x < n && y < m){

                if(board[x][y] == 'O' && vis[x][y] == 0){

                    vis[x][y] = 1;
                    q.push({x, y});

                }

            }

        }

    }

    if(border == false){
        for(auto [a, b] : cells){
            board[a][b] = 'X';
        }
    }

}

void solve(vector<vector<char>>& board) {
        
    int n = board.size() , m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m , 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(board[i][j] == 'O' && vis[i][j] == 0){
                bfs(i, j, board, vis, n, m);
            }

        }
    }


}