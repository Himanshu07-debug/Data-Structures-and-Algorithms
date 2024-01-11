// Given a string containing str from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the
// answer in any order.
// A mapping of str to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Input: str = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// RECURSIVE --------------------------------------------------------->>>

// LOGIC -->

// "abc" ke each character ko d, e, f ke sath laga diye...
// Suppose "234" -> Agar 34 muje apne saare Possible combinations bana ke de denga, I will add 2 ke characters one by one to all of them and 
// Required answer mil jya..
// Asking Recursion to prepare the Subset first is the naive one..
// We will do our Task first and then will ask Recursion to generate samne ke subsets.....


// We can use Unordered_map , map for storing phone keybad values..
// Most Efficient is using Vector

// TIME --> O(3 ^ n)  ... n = str.size() .. [ for each node, 3 childs will be there ]

// Space -> O(n) + O(10) + O(3 ^ n) [ ans vector ]


#include<bits/stdc++.h>
using namespace std;


void solve(int i, string &str, string &temp, vector<string> &ans, vector<string> &pad){

   if(i == str.size()){
    ans.push_back(temp);
    return;
   }

   string s = pad[str[i] - '0'];

   for(int j = 0; j < s.size() ; j++){

    temp.push_back(s[j]);
    solve(i+1, str, temp, ans, pad);
    temp.pop_back();

   }

}

vector<string> letterCombinations(string str){ 

    vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    string temp;

    solve(0, str, temp, ans, pad);

    return ans;


}


// Iterative ---------------------------------------->>

