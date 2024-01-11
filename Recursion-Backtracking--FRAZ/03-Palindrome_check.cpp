// 1. Two Pointers Appraoch 
// 2. n/2 tk traversal 

// Time -> O(n/2)


// By Recursion ---------->>

#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int l, int r){

    if(l >= r) return true;

    if(s[l] != s[r])  return false;

    return palindrome(s, l+1, r-1);

}

int main(){

    string s;
    cin >> s;

    if(palindrome(s, 0, s.size()-1) == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;

}