#include<bits/stdc++.h>
using namespace std;

// Knuth Morris Prath Algorithm

// In KMP, we build LPS array..

// lps[i] --> longest prefix suffix possible for the string str[0....i]

// Ex -->  a b c a b
// lps --> 0 0 0 1 2

// REMEMBER --> 
// for "ababa" --> Palindrome .. You will say lps[4] = 5 ... WRONG
// LPS states that you cant take entire string that You considered.. You can overlapp.. 
// You can take prefix of 0 to len - 2 & suffix of 1 to len - 1 atmax..

// So lps[4] = 3 [ aba is matching prefix-suffix ]


// NAIVE --------------->>>

// lps[0] = 0
// for loop from 1 .. n
//      for len = 1 to len <= i
//           Check str.substr(0, len) == str.substr(i-len+1, len) 
//                  update lps[i] = len


// O(n^3) --> substr and String matching will take atmax O(n) time


// OPTIMIZED ---> KMP

//          a b c a b c d a b c a  b  c  a 
//  indx -  0 1 2 3 4 5 6 7 8 9 10 11 12 13 

// lps[0] = 0
// lps[1] = 0
// lps[2] = 0
// lps[3] = 1
// lps[4] = 2

// Now lets see for indx = 5  --------------------->>>

// Can I use lps[4] value to decide lps[5] value ??
// lps[4] = 2 i.e there are max 2 length common prefix suffix

// 2 length already hai lps, agar str[2] & str[5] match ho jaaye to we can directly decide the lps length by add +1 to the previous lps value..

// Why You are sure that ki agar match hua to lps[i-1] + 1 hi max length value hongi lps[i] ke liye ??
// Becz agar jyada hoti to prev lps[i-1] ne consider kiya hota
// For above example, lps[4] ne sirf 2 store kiya hai, agar > 2 len prefix match hote suffix se to wo store krta i.e len = 3, 4

// THEREFORE , NOTE THIS --> Any lps[i] can have value atmax lps[i-1] + 1

// Observe, this indx of prefix character to check will always get by lps[i-1]

// for indx 5, lps[4] = 2 --> This is the indx of the prefix that I  have to check with str[i] for deciding either to increment the lps[i-1] or
// not

// lps[5] = 3
// lps[6] = 0
// lps[7] = 1
// lps[8] = 2
// lps[9] = 3
// lps[10] = 4
// lps[11] = 5
// lps[12] = 6

// Lets take example of indx = 13 ----------------------->>

// lps[i-1] = 6
// str[6] != str[13]  , NOW ??

// For the ( i - 1 ) characters i.e the prefix from [0 ... 5] that were matching, See if there exist a Suffix that match with prefix in 
// str[0 .. 5] for indx 5 ..
// lps[5] = 3, i.e there exist in suffix equal to prefix of 3 length..
// What this interprates ??
// pure 6 characters prefix se match nhi kiya to hum shorter common prefix suffix length dekhenge.. here LPS of length 3 exists i.e a b c
// For this next indx to check from prefix is --> lps[5] (yhi humko indx denga check krne ke liye ith character ke sath)

// lps[5] == 3, str[3] == str[13] , increment the length -> lps[13] = 3 + 1 

// if fir se match nhi hota, we backtrack more for shorter length , agar j == 0 ho jaata, we stop.. Ab length nhi bachi backtrack krke 
// prefix check krne ke liye


// For String matching ------------>>

// Same like Z algo, 
// pattern with $ append krdom starting me..
// jha pe lps ki value == pattern.length , Patten mil gya

// Only differene is that -->
// Z array me jha pe z[i] == pattern.length, this means ki ith character is the Starting for the pattern
// In KMP, if lps[i] == pattern.length, then this ith character is the ending character of the matched pattern 


vector<int> KMP(string str){

    int n = str.size();

    vector<int> lps(n, 0);

    for(int i=1;i<n;i++){

        // take the indx for matching --> To decide either to do lps[i-1] + 1 OR not
        int j = lps[i-1];

        // if matched
        if(str[j] == str[i]){
            lps[i] = j + 1;
            continue;
        }
        else{

            // backtrack loop for getting shorter common suffix as prefix
            while(j > 0 && str[j] != str[i]){

                j--;
                j = lps[j];

            }

            if(str[i] == str[j]){
                lps[i] = j + 1;
            }

        }

    }

    return lps;
    
}

int main(){

    vector<int> lps = KMP("aba$ababbababaaa"); 

    for(int x : lps) cout << x << " ";

    cout << endl;

}



// TIME --> O(n)

// All lps[i] will be atmax lps[i-1] + 1, so agar backtrack hua bhi and waha se increment hua bhi to wo O(n) se jyada nhi jayenga