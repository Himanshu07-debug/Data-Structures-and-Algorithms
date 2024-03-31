// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

// Input: s = "level"
// Output: "l"

#include<bits/stdc++.h>
using namespace std;

string longestPrefix(string str) {

    int n = str.size();

    vector<int> lps(n, 0);

    for(int i=1;i<n;i++){

        int j = lps[i-1];

        if(str[j] == str[i]){
            lps[i] = j + 1;
            continue;
        }
        else{

            while(j > 0 && str[j] != str[i]){

                j--;
                j = lps[j];

            }

            if(str[i] == str[j]){
                lps[i] = j + 1;
            }

        }

    }

    int x = lps[n-1];

    return str.substr(0, x);

        
}