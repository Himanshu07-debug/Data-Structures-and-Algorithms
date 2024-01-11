// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible 
// paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left),
// 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix 
// represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.


// arr = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

// 2 ≤ N ≤ 5
// 0 ≤ arr[i][j] ≤ 1


// All possible paths, All possible ways -> Can be solved by RECURSION 

// Ek path vector rkhna honga for keeping track of current path...
// We want Sorted path, so Hum phle D, L, R, U movement krnge... 

// TIME -> 
// For each cell, we have 4 choices...
// Also in the Worst case, when all arr[i][j] == 1, height of the Recursion tree will be n*n 
// So, No. of nodes --> TIME -> O(4 ^ (n*n) )

// SPACE --> O(n*n)


#include<bits/stdc++.h>
using namespace std;

void help(int i, int j, int n, vector<vector<int>> &arr, string &path, vector<string> &ans){

    if(i < 0 || j < 0 || i == n || j == n) return ;

    // Non restricted position
    if(arr[i][j] == 0) return;

    if( i == n-1 && j == n-1){
        ans.push_back(path);
        return;
    }

    // Making the Current cell as not-permited.. so that Iss cell pe firse call na hoye, This is included in path...
    // Adjacent cells will shuffle among themselves only
    arr[i][j] = 0;

    // Down
    path.push_back('D');
    help(i+1, j, n, arr, path, ans);
    path.pop_back();

    // Left
    path.push_back('L');
    help(i, j-1, n, arr, path, ans);
    path.pop_back();

    // Right
    path.push_back('R');
    help(i, j+1, n, arr, path, ans);
    path.pop_back();

    // Up
    path.push_back('U');
    help(i-1, j, n, arr, path, ans);
    path.pop_back();

    // Backtracking
    arr[i][j] = 1;


}


vector<string> findPath(vector<vector<int>> &arr, int n) {
        
    vector<string> ans;

    string path;

    help(0, 0, n, arr, path, ans);

    return ans;
        
}