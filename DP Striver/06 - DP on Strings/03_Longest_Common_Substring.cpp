// A substring of a string is a subsequence in which all the characters are consecutive. Given two strings, we need to find the longest 
// common substring.
// We need to print the length of the longest common substring.

// s1 = wasdijkl
// s2 = wsdjkl
// Output - 3  ( jkl )

// Recursive -------------------------->>

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int count, string str1, string str2){
 
    if (i == 0 || j == 0)
    {
        return count;
    }

    if (str1[i - 1] == str2[j - 1])
    {
        count = solve(i - 1, j - 1, count + 1, str1, str2);
    }

    int count1 = solve(i, j - 1, 0, str1, str2);

    int count2 = solve(i - 1, j, 0, str1, str2);

    count = max({count, count1,count2});

    return count;

}

// Why we are not writing Other thing in else ??
// Becz There can be the case jab current equal to wale ko count me consider na krna ho to get the maximum answer.
// Eg -> s1 = yxxzzxxxx , s2 = yzyzxxyxxz
// Here, s1 ka first 4 character max bna rha hai s2 ke last se. 


// TABULATION ---------------------------------------->>

// We can modify the approach we used in the article Longest Common Subsequence, in order to find the longest common substring. 
// The main distinguishing factor between the two is the consecutiveness of the characters.

// Thinking in terms of consecutiveness of characters


// We have two conditions:
// 1. if(S1[i-1] != S2[j-1]), the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value 
// (dp[i][j]) as 0.

// 2. if(S1[i-1] == S2[j-1]), then the characters match and we simply set its value to 1+dp[i-1][j-1]. We have done so because dp[i-1][j-1] 
// gives us the longest common substring till the last cell character (current strings -{matching character}). As the current cell’s character 
// is matching we are adding 1 to the consecutive chain.



int lcs(string &s1, string &s2){

    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(s1[i-1] == s2[j-1]){
                int val = 1 + dp[i-1][j-1]; 

                dp[i][j] = val; // Update the DP table

                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
            
        }
    }
    
    return ans; 
}

// SPACE OPTIMIZATION ------------------------------------------------------->>

int lcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1, 0); 
    vector<int> cur(m+1, 0);  

    int ans = 0; 

    
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; 
                cur[j] = val; 
                ans = max(ans, val); 
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }

        prev = cur; // Update the previous row with the values of the current row

    }
    
    return ans; 
}


int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}



