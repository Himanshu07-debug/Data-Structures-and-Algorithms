// Given an n x n board labeled in a Boustrophedon style, starting from square 1, find the minimum number of moves to reach square n^2. 
// Moves are determined by rolling a 6-sided die, and if a square has a snake or ladder, the player must move accordingly. Return -1 if reaching 
// square n^2 is not possible.

// Input: board = [[-1,-1,-1,-1,-1,-1],
                // [-1,-1,-1,-1,-1,-1],
                // [-1,-1,-1,-1,-1,-1],
                // [-1,35,-1,-1,13,-1],
                // [-1,-1,-1,-1,-1,-1],
                // [-1,15,-1,-1,-1,-1]]
// Output: 4
// Explanation: 
// In the beginning, you start at square 1 (at row 5, column 0).
// You decide to move to square 2 and must take the ladder to square 15.
// You then decide to move to square 17 and must take the snake to square 13.
// You then decide to move to square 14 and must take the ladder to square 35.
// You then decide to move to square 36, ending the game.
// This is the lowest possible number of moves to reach the last square, so return 4.



// LOGIC --------------------------------------------------------------------------------------------->>>


// We have to Find -> least number of moves required to reach the square n^2. If it is not possible to reach the square, return -1.

// Each cell se mai 6 cells pe jaa sakta hu... 
// Each of This 6 cells se further 6 cells pe jaa sakta hu.... 
// Recursion Tree Dekho.... No. of nodes will be Like this -> 1, 6, 36, 216, ...

// We are moving level by level ----> BFS

// dist[] array rkhnge Height ka track rkhne ke liye i.e the no. of moves, If dist[parent] = 1, then dist[child] = dist[parent] + 1

// dist[n^2] will store our answer....

// More Details --> Pdf



// Why not DFS ? -> https://leetcode.com/problems/snakes-and-ladders/solutions/3098316/reason-why-dfs-won-t-work-in-some-testcases/

// Here Cycles are Possible and hence agar DFS use kiye to Recursively, cycle me hi iterate krte rah jayenge....


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

int snakesAndLadders(vector<vector<int>> &board) {

    int n = board.size(), indx = 1;

    // 1D - array
    vector<pair<int, int>> cells(n*n+1); 

    vector<int> columns(n);

    for(int i=0;i<n;i++) columns[i] = i;

    // Converting 2D - array to 1D - array
    for (int row = n - 1; row >= 0; row--) {

        for (int column : columns) {
            cells[indx] = {row, column};
            indx++;
        }

        // Reversing for next upper row --> Revering the numbering of Columns, ZIG-ZAG
        reverse(columns.begin(), columns.end());
    }


    // BFS starts here

    vector<int> dist(n*n + 1, -1);  
    // initialized by -1, -1 represent not Visited Cells

    // Starting place
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {

        int curr = q.front();
        q.pop();

        // cout << curr << " ---> ";         ----> To visualize the Recursion Tree

        for (int next = curr + 1; next <= min(curr+6, n*n); next++) {

            // Next no. ka row and col number boards matrix me....
            auto [row, column] = cells[next];

            // Checking (row, col) pe ladder or snake hai Kya ??
            int destination = board[row][column] != -1 ? board[row][column] : next;

            // If the Destination cell is not visited, make it visited and add it in the queue ... 
            if (dist[destination] == -1) {

                dist[destination] = dist[curr] + 1;

                q.push(destination);

                // cout << destination << " ";   ----> To visualize

            }

        }

        // cout << endl;      
    }

    return dist[n*n];

}


// NOTE -> BFS me Hum level-by-level jaa rhe hai, so first time dist[n^2] jo update hua, wo Shortest moves ka hi honga .. Kyuki kam levels me
//         gye

// Can use Visited[] array, but dist[] is enough to handle both

// TIME -> 
// O(n^2) -> Preparation of 1D Array 
// O(n^2) -> Worst case me saare cells Queue me add honge

// SPACE -> 
// O(n^2) -> Distance array 
// O(n^2) -> Cells array


// OPTIMIZATION -> 
// Cells array use krne ki zaroorat nhi, Cell no. dedo, (row, col) mil jayega -> See PDF