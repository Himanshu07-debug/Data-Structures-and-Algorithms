#include <bits/stdc++.h>
using namespace std;

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

    int i = n, j = m;

    //     for (int ind1 = 1; ind1 <= n; ind1++) {

    //     for (int ind2 = 1; ind2 <= m; ind2++) {

    //         cout << dp[ind1][ind2] << " ";

    //     }

    //     cout << endl;

    // }


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

















