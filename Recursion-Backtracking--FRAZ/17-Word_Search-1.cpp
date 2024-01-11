// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Constraints --->
// 1 <= m, n <= 6
// 1 <= word.length <= 15


// LOGIC -------------------------->>>

// Checking in all adjacent cells, this is same as FLOOD FILL ALGORITHM..

// Iterate through the matrix and start from the valid starting cell i.e word[0] .. Uske aage Flood Fill ke calls batayenge Elements mile kya 
// sequentially... Agar Word.size() tk indx pahuch gya, means Word present hai, we will return true...



#include<bits/stdc++.h>
using namespace std;

bool help(int i, int j, int z, vector<vector<char>>& board, string &word, int n, int m){

    // Word found
    if(z == word.size()) return true;

    // Boundary Condition
    if(i < 0 || j < 0 || i == n || j == m) return false;

    // Character != required character.. Going in Wrong path
    if(board[i][j] != word[z]) return false;

    // Doing to avoid Recursion Running Infinitely.... Adjacent wale ek dusre call krte rah jayenge...
    board[i][j] = '#';

    bool op1 = help(i+1, j, z + 1, board, word, n, m);
    bool op2 = help(i-1, j, z + 1,  board, word, n, m);
    bool op3 = help(i, j+1, z + 1, board, word, n, m);
    bool op4 = help(i, j-1, z + 1, board, word, n, m);

    // Backtracking
    board[i][j] = word[z];

    return op1 | op2 | op3 | op4;

}

bool exist(vector<vector<char>>& board, string word) {

    int n = board.size() , m = board[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(board[i][j] == word[0]){

                bool f = help(i, j, 0, board, word, n, m);

                if(f) return true;

            }

        }
    }
    return false;

}


// TIME --> 
// Worst case me aap n*m baar call kronge and Each Call ki max. height word.size() == k hongi...
// n * m * O(4^k)

// SPACE --> n * m * k


