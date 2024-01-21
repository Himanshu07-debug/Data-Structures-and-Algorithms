// You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to 
// find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as 
// integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].

// To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to 
// either MATRIX[i + 1][j] or MATRIX[i][j + 1].

// m = 2 , n = 2
// Ans -> 2 
// Path 1 = (0, 0) -> (0, 1) -> (1, 1)
// Path 2 = (0, 0) -> (1, 0) -> (1, 1)

// We go from (m-1, n-1) to (0, 0) --> Striver Way

// f(i, j) -> Total no. of unique paths from (0,0) to (i, j)

// RECURSIVE -------------------->>

// The max. length of any path in m*n grid from (0,0) to (n-1, m-1) is (m - 1) + (n - 1)
// Top aap (m - 1) times down chaloge and (n - 1) times right chaloge

// TIME -> O(2 ^ (m - 1 + n - 1)) ==> O(2 ^ (m + n - 2))
// SPACE -> O(m * n)

// Overlapping Subproblems ---->

// From both move, you can observe Common point in the both path
// (m-1, n-1) ->  (m-1, n-2) -> (m-2, n-2)
// (m-1 , n-1) -> (m-2, n-1) -> (m-2, n-2)


#include <bits/stdc++.h>
using namespace std;


// Memoization ----------------------->>

int count(int i, int j, vector<vector<int>> &dp){

	if( i == 0 && j == 0) return 1;

	if( i < 0 || j < 0 ) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int left = count(i, j - 1, dp);
	int up = count(i-1, j, dp);

	return dp[i][j] = left + up;

}

int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m, vector<int> (n, -1));

	return count(m-1, n-1, dp);

}



// TIME --> O(m * n)

// Space -> O(m * n) + [ O(m - 1 + n - 1) i.e O(m + n - 2) ] ( call stack )


// ITERATIVE --------------------------->>

int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m, vector<int> (n, 0));

	dp[0][0] = 1;

	for(int i=0;i<m;i++){
		for(int j = 0; j< n ;j++){

			if( i == 0 && j == 0) continue;

            int up = 0;
            int left = 0;

			if(i - 1 >= 0) up = dp[i-1][j];

			if(j - 1 >= 0) left = dp[i][j-1];

            dp[i][j] = up + left;

		}
	}

	return dp[m-1][n-1];

}

// SPACE -> O(m * n)


// SPACE OPTIMIZATION ------------------->>

int uniquePaths(int m, int n) {
	// Write your code here.

	vector<int> prev(n, 0);

	for(int i=0;i<m;i++){

		vector<int> curr(n, 0);

		for(int j = 0; j< n ;j++){

			if(i == 0 && j == 0) curr[j] = 1;
			else{

				int up = 0, left = 0;

				if(i - 1 >= 0) up = prev[j];

				if(j - 1 >= 0) left = curr[j-1];

				curr[j] = left + up;

			}

		}

		prev = curr;
		
	}

	return prev[n-1];

}

// SPACE -> O(n)


// This is an Google Interview Question --> Time => O(m * n) gives TLE ...

// We will use Combinotarics... 
// All unique paths me no. of down movements and right movements will be same..
// Total moves -> (m - 1 + n - 1) -> (m + n - 2)
// So, You have _ _ _ ... _ ( m + n - 2) places to fill
// ANS -> No. of ways of placing down moves on the available moves / No. of ways of placing right moves on Available moves..
// Therefore, ANS ==> (m + n - 2) C (m - 1)  OR  (m + n - 2) C (n - 1)

// NOTE -> Agar ek move ko arrange krne ke possible ways nikal liye, baaki empty places pe fix dusri wali move aayengi -> No extra Path arrangement

// TIME -> O(m - 1) or O(n - 1)
// SPACE -> O(1)


int uniquePaths(int m, int n) {

	int total = n + m - 2;
	int d = m - 1;

	double res = 1;

	for(int i=0; i < d; i++){

		res = res * (total - i);
		res = res/(i + 1);

	}

	return (int)res;

}