#include <bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings,
//  return any of them.

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".


// LOGIC ----------------------------------------------------->>

// Framework -> DP, FORM -> DP on Strings, In this Form, Any Previously known Problem for this --->

// Both String ka LCS final/ answer String me ek hi baar aayenga... So What we can use ???

// We have done Printing of LCS ... Here also we have to Print also at once.. We can take advantage of it. 

// What about Rest characters of Both String , LCS ke aage piche kaise set kronge... 

// We have Reach to the Logic of Printing the LCS... Uska Tabulation ka Matrix build kro and Find Observation , From there only we will get 
// further logic

// DRY RUN is must to get Observation... 

// For visual -> https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/

// When s1[i-1] != s2[j-1] ...
// We move to eiter upper or left cell whichever value is greater ...
// Whichever Cell I moved, it is sure that ki mai wo cell pe wapas nhi aa paunga...
// So before moving, add that characters of the respective string s1 or s2 to the Answer String

// MOST BEAUTIFUL THING HERE WAS THAT KI MATRIX KE WAJAH SE CHARACTERS INDEXES WISE THE, HUME ORDER KA TENSION NHI HUA


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
                ans = s1[i-1] + ans;
                i--;
            }
            else{
                ans = s2[j-1] + ans;
                j--;
            }

        }

    }

    while(i > 0){
        ans = s1[i-1] + ans;
        i--;
    }

    while(j > 0){
        ans = s2[j-1] + ans;
        j--;
    }

    return ans; // Return the length of the Longest Common Subsequence

}

string shortestCommonSupersequence(string str1, string str2) {

    return lcs(str1, str2);
        
}