
#include<bits/stdc++.h>
using namespace std;


// LINK -> https://leetcode.com/problems/decode-string/description/

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"


// 1 <= s.length <= 30
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].


// LOGIC ------------------------------------------------------------------->>>>

// I am lazy, I will say Recursion tum merko K[ ] ke andar ka string content dedo, mai usko k baar final string me add kar dunga 

string decodeString(const string& s, int& i) {

    string word = "";
    
    while (i < s.length()) {

        if (!isdigit(s[i])){
        }
        if(isdigit(s[i])){

            int x = 0;

            while (i < s.length() && isdigit(s[i])){

                x = x * 10 + (s[i] - '0');
                i++;

            }
                
            // '[' ke liye
            i++; 

            // Calling Recursion for string content
            string t = decodeString(s, i);

            // ']' ke liye
            i++; 
            
            // Append in Final String x times
            for(int i=0;i<x;i++){
                word += t;
            }

        }
        // End of our Bracket
        else if(s[i] == ']') break;

        else{
            word += s[i];
            i++;
        }

    }
    
    return word;
}

string decodeString(string s) {

    int i = 0;

    return decodeString(s, i);

}


// ITERATIVE ------------------------------------------->>>

// Using Stack

string decodeString(string s) {

    int n = s.size();

    stack<char> st;

    for(int i=0;i<n;i++){

        if(s[i] == ']'){

            string temp = "";

            while(!st.empty() && st.top() != '['){

                temp = st.top() + temp;                // insert like this, no need to reverse later temp, jo order me chahiye, wahi order me
                st.pop();

            }

            st.pop();               // for '['

            string num = "";

            while(!st.empty() && isdigit(st.top())){

                num = st.top() + num;

                st.pop();

            }

            int x = stoi(num);

            for(int j=0;j<x;j++){

                for(char c : temp) st.push(c);

            }

        }
        else{
            st.push(s[i]);
        }

    }

    string res = "";

    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    return res;
        
}

// Can Reduce the Size of the Code by Using final string in place of Stack, st.top() ke jagah res.back() , st.pop() -> res.pop_back()


// Can reduce the size of the Code .


string decodeString(string s) {

    int n = s.size();

    stack<string> st;

    string curr = "", num = "";

    for(int i=0;i<n;i++){

        if(s[i] == '['){

            st.push(curr);
            st.push(num);

            curr = "";
            num = "";

        }
        else if(s[i] == ']'){

            int x = stoi(st.top());
            st.pop();

            string prev = st.top();
            st.pop();

            for(int j=0;j<x;j++){

                prev += curr;

            }

        }
        else if(isdigit(s[i])){
            num += s[i];
        }
        else{
            curr += s[i];
        }

    }

    return curr;

}



