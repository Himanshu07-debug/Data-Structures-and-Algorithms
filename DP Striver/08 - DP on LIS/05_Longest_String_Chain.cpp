#include<bits/stdc++.h>
using namespace std;

bool compare(string& s1, string& s2){

    if(s1.size() != s2.size() + 1) return false;
    
    int diff = 0, x = 0;

    for(int k = 0; k < s1.size() && diff <= 1; k++){

        if(x < s2.size() && s1[k] == s2[x]){
            x++;
        }
        else{
            diff++;
        }

    }

    return (diff == 1);

}

// Sorting based on lengths

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}


int longestStrChain(vector<string>& arr){

    int n = arr.size();
    
    sort(arr.begin(), arr.end(),comp);

    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i < n; i++){
        
        for(int j = 0; j <=i-1; j++){
            
            if( compare(arr[i], arr[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;

}