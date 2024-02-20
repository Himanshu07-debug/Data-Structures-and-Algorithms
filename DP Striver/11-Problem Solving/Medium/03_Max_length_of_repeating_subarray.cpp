#include<bits/stdc++.h>
using namespace std;

 int findLength(vector<int>& arr1, vector<int>& arr2) {
        
    int n = arr1.size() , m = arr2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(arr1[i-1] == arr2[j-1]){
                int val = 1 + dp[i-1][j-1]; 

                dp[i][j] = val;

                ans = max(ans, val);
            }
            else
                dp[i][j] = 0;
            
        }
    }
    
    return ans; 



}