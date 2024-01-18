// There is an n*n matrix. Place n queens in it such that no two queen attack each other.
// Return all possible arrangements. 

// Normal aap kar donge...

// NAIVE ------------------------------------->>>

// TIME AND SPACE ANALYSIS ---------------------->>

// SPACE -> O(n)

// TIME -> 
// First row me place ke n options...
// Second row me place krne ke (n - 1) options.
// third row me place krne ke (n - 2) options...
//   ....
// Similarly, for the last row, only 1 options...
// n * (n-1) * (n-2) * ..... * 1 =========> n!

// Each cell me place krne ke liye isSafe() function phle call kar ho for checking... --> O(n)

// TIME ---->> O( n * n! )

// By no. of nodes logic also, O(n!) nodes are possible


// OPTIMIZATIONS -------------------------->>>

// Hum isSafe() ki checking ko nullify kar sakte hai...

// Before placing a queen in a cell, we check in top side ki koi Queen same column , Same top-right , Same top-left corner me to place nhi hai...

// For same column -> Maintaining a column array..
// For top-right Diagonal & top-left diagonal ---> See Image

// Here isSafe() ka O(n) time is Nullified and Hence time -> O(n!)


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &chessboard, int n){

    int tempI = i;

    // Column
    while(tempI >= 0){

        if(chessboard[tempI][j] == 1) return false;
        tempI--;

    }

    tempI = i;
    int tempJ = j;

    // top left diagonal
    while(tempI >= 0 && tempJ >= 0){

        if(chessboard[tempI][tempJ] == 1) return false;
        tempI--;
        tempJ--;

    }

    tempI = i;
    tempJ = j;

    // top right diagonal
    while(tempI >=0 && tempJ < n){

        if(chessboard[tempI][tempJ] == 1) return false;
        tempI--;
        tempJ++;

    }

    return true;

}

void help(int i, vector<vector<int>> &chessboard, vector<vector<int>> &ans, int n){

    if(i == n){

        // In Question, it is said that flatten the matrix vector is need to be added in the answer vector...

        vector<int> temp;

        for(int j=0;j<n;j++){
            for(int k = 0; k < n; k++){
                temp.push_back(chessboard[j][k]);
            }
        }

        ans.push_back(temp);

        return;

    }

    
    for(int j=0;j<n;j++){

        if(isSafe(i, j, chessboard, n)){

            chessboard[i][j] = 1;

            // Calling for next row
            help(i+1, chessboard, ans, n);

            // Backtracking
            chessboard[i][j] = 0;

        }

    }


}

vector<vector<int>> nQueen(int n){

    vector<vector<int>> chessboard(n, vector<int> (n , 0));

    vector<vector<int>> ans;

    help(0, chessboard, ans, n);

    return ans;

}


// OPTIMIZED CODE ------------------------------>>>

// Copy paste the same code, just few changes

void helpOptimized(int i, vector<vector<int>> &chessboard, vector<vector<int>> &ans, int n, vector<int> &col, vector<int> &tl, vector<int> &tr){

    if(i == n){

        vector<int> temp;

        for(int j=0;j<n;j++){
            for(int k = 0; k < n; k++){
                temp.push_back(chessboard[j][k]);
            }
        }

        ans.push_back(temp);

        return;

    }

    
    for(int j=0;j<n;j++){

        if(col[j] == 0 && tl[i - j + n - 1] == 0 && tr[i + j] == 0){

            chessboard[i][j] = 1;
            col[j] = tl[i - j + n - 1] = tr[i + j] = 1;

            // Calling for next row
            help(i+1, chessboard, ans, n);

            // Backtracking
            chessboard[i][j] = 0;
            col[j] = tl[i - j + n - 1] = tr[i + j] = 0;

        }

    }

}


vector<vector<int>> nQueenOptimized(int n){

    vector<vector<int>> chessboard(n, vector<int> (n , 0));

    vector<vector<int>> ans;
    vector<int> col(n, 0), tl(2*n, 0), tr(2*n, 0);

    helpOptimized(0, chessboard, ans, n, col, tl, tr);

    return ans;

}

