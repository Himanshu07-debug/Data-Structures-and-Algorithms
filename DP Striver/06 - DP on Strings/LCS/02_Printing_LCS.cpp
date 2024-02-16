#include <bits/stdc++.h>
using namespace std;

// Algorithm ------------------------------->>

// 1. We start from cell dp[n][m]. Initially i = n and j = m.

// 2. At every cell, we will check if S1[i-1] == S2[j-1], if it is then it means this character is a part of the longest common subsequence. 
//      So we will push it to the ans string str. Then we will move to the diagonally top-left(↖)  cell by assigning i to i-1 and j to j-1.

// 3. Else, this character is not a part of the longest common subsequence so we include it in ans string. Originally this cell got its 
// value from its left cell (←) or from its top cell (↑). Whichever cell’s value will be more of the two, we will move to that cell.

// 4. We will continue till i>0 and j>0, failing it we will break from the loop.

// 5. After breaking, either i>0 or j>0 (only one condition will fail to break from the while loop), if(i>0) we push all the characters 
// from S1 to ans string, else if(j>0), we push all the remaining characters from S2.

// 6. At last, we reverse the ‘ans’ string and we get our answer.

// Yeah reversal Part avoid kar sakte hai by adding the characters in the answer String at front


string lcs(string &s1, string &s2) {

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    string ans = ""; 

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }


    for (int ind1 = 1; ind1 <= n; ind1++) {

        for (int ind2 = 1; ind2 <= m; ind2++) {

            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }

    }

    //     for (int ind1 = 1; ind1 <= n; ind1++) {

    //     for (int ind2 = 1; ind2 <= m; ind2++) {

    //         cout << dp[ind1][ind2] << " ";

    //     }

    //     cout << endl;

    // }


    int i = n, j = m;

    while(i > 0 && j > 0){

        if(s1[i-1] == s2[j-1]){
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else{

            int x = dp[i-1][j];
            int y = dp[i][j-1];

            if(x >= y){
                i--;
            }
            else{
                j--;
            }

        }

    }

    return ans; // Return the length of the Longest Common Subsequence

}


void findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	

    cout << lcs(s1, s2) << endl;


}

int main() {

  string s1 = "ababa";
  string s2 = "cbbcad";

  cout << "The Longest Common Subsequence is ";
  findLCS(5, 6, s1, s2);
}

















