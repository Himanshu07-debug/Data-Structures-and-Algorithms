// Return all Permutations of the String str in Lexicographically increasing order...


// LOGIC --------------------->>

// For a String of length n, we can have n! permutations...

// We know that, while finding Permutation, we put all the remaining elements at the R.H.S of the string to the Current position and Do this Thing
// Recursively for the further position...

// But we are lazy, mai sirf first position pe saare remaining elements R.H.S ke laaunga, Baaki aage ke position ka Recursion dekh lenga..


#include<bits/stdc++.h>
using namespace std;

void permutation(string str, int pos, vector<string> &ans){

    if(pos == str.size()){
        ans.push_back(str);
        return;
    }

    for(int i=pos;i<str.size();i++){

        // fix the ith indx character to the current position
        swap(str[i], str[pos]);

        permutation(str, pos+1, ans);

        // undo the change we had made
        swap(str[i], str[pos]);

    }


}

vector<string> solve(string str){

    vector<string> ans;

    permutation(str, 0, ans);

    // In Question, Sorted Output is required

    sort(ans.begin(),ans.end());

    return ans;

}

// Observe the Recursion Tree..

// TIME -> n! permutations i.e leaf possible, sabke generation ke liye n baar iterate ==> n * n!

// SPACE -> At any moment, There can be max. n characters i.e str elements in the Recursion Stack -> O(n) , uske baad Backtrack ho rha hai next
//          permutation banane ke liye. Also a Vector<string> will store n! elements... 
// Total Space ==> O(n) + O(n!)


int main(){

    string str;
    cin >> str;

    vector<string> ans = solve(str);

    for(string s : ans){
        cout << s << " ";
    }


    return 0;

}