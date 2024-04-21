#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSP;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// You are given a 0-indexed string word and an integer k.

// At every second, you must perform the following operations:

// Remove the first k characters of word.
// Add any k characters to the end of word.
// Note that you do not necessarily need to add the same characters that you removed. However, you must perform both operations at every second.

// Return the minimum time greater than zero required for word to revert to its initial state.

// Input: word = "abacaba", k = 3
// Output: 2
// Explanation: At the 1st second, we remove characters "aba" from the prefix of word, and add characters "bac" to the end of word. Thus, 
// word becomes equal to "cababac".
// At the 2nd second, we remove characters "cab" from the prefix of word, and add "aba" to the end of word. Thus, word becomes equal
//  to "abacaba" and reverts to its initial state.
// It can be shown that 2 seconds is the minimum time greater than zero required for word to revert to its initial state.
// Example 2:

// Input: word = "abacaba", k = 4
// Output: 1
// Explanation: At the 1st second, we remove characters "abac" from the prefix of word, and add characters "caba" to the end of word. 
// Thus, word becomes equal to "abacaba" and reverts to its initial state.
// It can be shown that 1 second is the minimum time greater than zero required for word to revert to its initial state.

// Constraint --> 1 <= k <= n <= 1e6


// LOGIC ---->
// Worst case me puri string remove karni padegi and that will be the max cnt....

// For min. no of operations ?? --> We have to see that remaining string that is to be removed , is it equal to the prefix of the remaining string
// len i.e s.size() - i (for any indx i)

// TYPICAL Z-Algorithm Question

// NAIVE ------------------------>>

int minimumTimeToInitialState(string s, int k) {

    int c = 0;

    c++;

    for(int i=k;i<s.size();i+=k){

        string tmp1 = s.substr(0, s.size() - i);

        string tmp2 = "";

        for(int j=i;j<s.size();j++) tmp2 += s[j];

        if(tmp1 == tmp2) return c;
    
        c++;

    }

    return c;
        
}


// OPTIMIZED -------------------------------------------------->>>

// Removing the loop overhead by Z vector Computation


vector<int> zMatch(string s){

    vector<int> z(s.size() , 0);

    // Initial range
    int l = 0, r = 0;

    for(int i = 1; i < s.size(); i++){

        // ith character is within the last boundary
        if(i < r){
            z[i] = z[i - l];

            // CASE 1
            // Handle case of z[i] reaching for characters beyond what we have seen at r i.e Restrict the Boundary
            if(i + z[i] > r){
                z[i] = r - i;
            }

        }

        // CASE 2
        // Look for more match beyond the current calculation of i
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]])  z[i]++;

        // Update boundary l, r if expansion happen
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
        
    }

    return z;

}


int minimumTimeToInitialState(string str, int k) {

    vector<int> z = zMatch(str);

    int c = 1;

    for(int i=k;i<str.size();i+=k){

        int len = str.size() - i;

        if(z[i] == len) return c;

        c++;

    }

    return c;
        
}




// int main(){

//     ios::sync_with_stdio(false); cin.tie(NULL);

//     // Your code here
    
    

//     return 0;
// }