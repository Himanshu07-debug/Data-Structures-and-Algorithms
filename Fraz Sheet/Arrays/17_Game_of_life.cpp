#include<bits/stdc++.h>
using namespace std;

// There are 3 conditions for Live cell and 1 condition for dead cell...
// All of them depends on a Common Parameter --> no. of live cells

// NAIVE -> O(n * m) SPACE 

void gameOfLife(vector<vector<int>>& arr) {

    int m = arr.size() , n = arr[0].size();

    vector<pair<int,int>> dirs = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1} };

    vector<vector<int>> cnt(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){

            int c = 0;

            for(auto [a, b] : dirs){

                int x = i + a;
                int y = j + b;

                if(x >= 0 && y >= 0 && x < m && y < n && arr[x][y] == 1){
                    c++;
                }

            }

            cnt[i][j] = c;

        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            int c = cnt[i][j];

            if(arr[i][j] == 1){

                if(c < 2) arr[i][j] = 0;
                else if(c > 3) arr[i][j] = 0;
                else arr[i][j] = 1;

            }
            else{

                if(c == 3) arr[i][j] = 1;

            }

        }
    }

}

// OPTIMAL --------------------->>

// live cell dead ho rha hai --> change it by -1 .. therefore, baaki cells absolute value check krnge to live milenga

// Dead cell live ho rha hai --> Change it by 2 ... Other Cells 1 hai kya check krnge, to 0 milenga

// SPACE -> O(1)

void gameOfLife(vector<vector<int>>& arr) {

    int m = arr.size() , n = arr[0].size();

    vector<pair<int,int>> dirs = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1} };

    // vector<vector<int>> cnt(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){

            int live = 0;

            for(auto [a, b] : dirs){

                int x = i + a;
                int y = j + b;

                if(x >= 0 && y >= 0 && x < m && y < n && abs(arr[x][y]) == 1){    // checking absolute values
                    live++;
                }

            }

            if(arr[i][j] == 1){
                if(live < 2 || live > 3) arr[i][j] = -1;
            }
            else{
                if(live == 3) arr[i][j] = 2;
            }

        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(arr[i][j] == -1) arr[i][j] = 0;
            else if(arr[i][j] == 2) arr[i][j] = 1;

        }
    }

}
