// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
// Return the maximum possible length of s.

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.




// We can Go with Subset logic... pick a string and concatenate if valid or skip it

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &selected, string &s){

    vector<int> selfCheck(26, 0);

    for(int i=0; i < s.size() ; i++){

        if(selfCheck[s[i] - 'a'] == 1) return false;

        selfCheck[s[i] - 'a'] = 1;

    }

    for(int i=0;i<s.size();i++){

        if(selected[s[i] - 'a'] == 1) return false;

    }

    return true;

}


int help(int i, vector<string> &arr, vector<int> &selected, int len){

    if( i == arr.size()) return len;

    string str = arr[i];

    // Check for Validity of current string
    if(check(selected, str) == false){

        // not valid string
        return help(i+1, arr, selected, len);

    }
    else{

        // Valid hai, pick or skip

        // pick 
        for(int j=0;j<str.size();i++){

            selected[str[i] - 'a'] = 1;

        }

        len += str.size();

        int pick = help(i+1, arr, selected, len);

        len -= str.size();

        for(int j=0;j<str.size();j++){
            selected[str[i] - 'a'] = 0;
        }

        int skip = help(i+1, arr, selected, len);

        return max(pick, skip);

    }


}



int maxLength(vector<string>& arr) {

    vector<int> selected(26, 0);

    return help(0, arr, selected, 0);

        
}

// TIME --> O(2^n) * O(26)     ... (max length of any string on the array)
// SPACE --> O(n)