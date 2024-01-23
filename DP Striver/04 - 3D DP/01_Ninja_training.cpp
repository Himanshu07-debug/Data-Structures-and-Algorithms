// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and 
// he wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of 
// them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, 
// and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

// Input: r = 3, c = 4  ,, grid = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
// Output: 21

// Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.
// Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.
// Hence the total number of chocolates collected will be 12 + 9 = 21.


// LOGIC -------------------------------------->>>>

// In this Question, We have Fixed Starting Points and Variable Ending pts.
// i.e Hume Reverse Striver way jna padega..

// GREEDY will not work...

// One Approach can be ki mai First Alice ka max. path chocalate nikal lu and then Bob ka, but in this Question, Same Cell pe koi ek hi le sakta
// hai, so hume common jo dono path me hai, unhe figure out krke Total answer se remove krna honga....

// Another Approach which is the BEST is that we will move Alice and Bob together .. Jab common aayenga to sirf Ek baar add krnge aur
// Agar common cell nhi aaya to dono ka add krnge...

// Now, lets think how to write Recursion ??

// TASK 1 -> Parameters and Recurrence Relation ->

//  We need to define the function with four parameters i1,j1,i2,j2 to describe the positions of Alice and Bob at a time.

// But do we really need 4 parameters, becz We are sure that each time, Dono Alice and Bob sath me next row pe move krnge... 
// So row ke liye i1, i2 rkhne ki need nhi, single row parameter se bhi ho jayega...

// f(i,j1,j2) => will give us the maximum number of chocolates collected by Alice and Bob from their current positions to the last position.


// TASK 2 -> Base case -> 

// When i = n-1, then if j1 == j2 (same column , i.e common cell) , return grid[i][j1] , otherwise when j1 != j2, grid[i][j1] + grid[i][j2]

// TASK 3 -> Transition , STUFF ->

// If Alice move Bottom-left, Bob can move any of the 3 allowed Places..
// this means, for each move of one, Lets consider Alice, other i.e Bob can make all the 3 moves...

// So here, 9 combos are Possible, One way is to make 9 lines for all call hard code, Another way is to use a Below trick

#include <bits/stdc++.h> 
using namespace std;

int maxChoco(int i, int j1, int j2, vector<vector<int>> &grid, int c, int r, 
    vector<vector<vector<int>>> &dp){

    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e9;

    if(i == r - 1){

        // same cell
        if(j1 == j2)  return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];

    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int mx = 0;

    for(int dj1 = -1 ; dj1 <= 1; dj1++){

        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

            int value = 0;

            if(j1 == j2) value += grid[i][j1];
            else value += grid[i][j1] + grid[i][j2];

            value += maxChoco(i+1, j1 + dj1, j2 + dj2, grid, c, r, dp);

            mx = max(mx, value);

        }

    }

    return dp[i][j1][j2] = mx;

}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return maxChoco(0, 0, c-1, grid, c, r, dp);

}

// RECURSION -> O(3^n * 3^n)  , Space -> O(n) 
// For each movement of alice, we have 3 moves of Bob.. O(3^n) * O(3^n) ==> O( 9^n )


// Memoization -> 
// Time -> No. of states -> O(n * m * m ) * O(9) .. Each state, 9 ka loop
// Space -> O(n) + O(n * m * m)


// ITERATIVE ------------------------------------------------->>>

// NOTE -> Writing Iterative is Very easy once Recursive likh diye...
// REMEMBER, Jyada Sochna nhi hai, Flow of states dekho and Parameters dekho -> Once You prepare each possible states in loops -> Copy paste 
//           Recursive Code

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));

    for(int j1=0;j1 < c; j1++){
        for(int j2 = 0;j2<c;j2++){

            if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];

        }
    }

    // State formation -> 3 loops me

    for(int i = r-2;i>=0;i--){

        for(int j1=0;j1 < c; j1++){

            for(int j2 = 0;j2<c;j2++){

                // State Formation, Now just Copy paste Recursive code

                int mx = 0;

                for(int dj1 = -1 ; dj1 <= 1; dj1++){

                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){

                        int value = 0;

                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];

                        int x = j1 + dj1;
                        int y = j2 + dj2;

                        if(x >= 0 && x < c && y >=0 && y < c){
                            value += dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value += -1e9;  // Not valid path
                        }

                        mx = max(mx, value);

                    }

                }
                dp[i][j1][j2] = mx;
            }
        }
    }

    return dp[0][0][c-1];

}


// SPACE OPTIMIZATION ------------------------------->>>

// Hum row no. ka parameter nullified kar sakte hai...

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {

    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    // Initialize 'front' for the last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += front[j1 + di][j2 + dj]; // Include the value from the 'front' array

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                cur[j1][j2] = maxi; // Store the maximum result for this state in the 'cur' array
            }
        }
        front = cur; // Update 'front' with the values from 'cur' for the next iteration
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the 'front' array
    return front[0][m - 1];
}

