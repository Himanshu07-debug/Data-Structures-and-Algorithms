#include<bits/stdc++.h>
using namespace std;

// Z Algo gives you an Z - array where -->
// Z[i] = Longest common Prefix of str[0 ... n] & str[i ... n]

// Let str = " a b c d a b c a b c "
// zArray -    0 0 0 0 3 0 0 3 0 0

// NAIVE ------------------>>

void Z_Algorithm(string &str, int n){

    vector<int> zArray(n);

    zArray[0] = 0;

    for(int i=1;i<n;i++){

        int j = 0 , k = i;

        while(k < n && str[j] == str[k]){
            j++;
            k++;
        }

        zArray[i] = j;

    }

    for(int x : zArray) cout << x << " ";

    cout << endl;

}

// TIME --> O(n^2)


// Let str = " a b c d a b c a b c "
// zArray -    0 0 0 0 3 0 0 3 0 0

// from indx 4 , 'abc' is the match --> len = 3 ..
// So, for indx 5, 6 --> there is no need to compute them, just use the past calculated zArray values of b , c
// similar for range (7, 9)
// Z[i] = Z[i - l]  where l, r is the range [ like for (4, 6) -> l = 4 , r = 6 , etc ]

// NOTE --> Here to understand, it is written r = 6 but in the range (l, r) , r is there to take care of size i.e r = l + length == 7
// See in Algo, You will understand more


// There are some cases, where this Logic of directly copy pasting the previous calculated values FAILS ------------------

// CASE 1 ----->>> Ans for the indx < zArray past value

// Ex --> " a a a a a b c d "
// zArray - 0 4 4 4 4 0 0 0

// Dry Run --> 
// At indx 1 ==> 4 length common prefix is found. Range - (1, 4) -->  l = 1 to r = 4
// therefore, for indx 2, 3, 4  ---> Z[i] = Z[i - l]
// All will be 4 which is Wrong 
// Valid Ans < zArray past value

// PROBLEM where arise ??
// Actually the range further indexes i.e from l + 1 are considering prefix length beyond the Boundary
// Ex -> indx 2 is considering --> a a a b , That's why 4

// SOLUTION for CASE - 1 ----------->>
// If copying make You go beyond the boundary(r) , then restrict the boundary. i.e 
// if ( i + Z[i] <= r ), then Z[i] = Z[i - l]
// else Z[i] = r - i

// Ex --> " a a a a a b c d "
// zArray - 0 4 3 2 1 0 0 0


// CASE 2 ------------>>>  Ans for the indx > zArray past values

// Ex -->  " a b a b a d a b a b a b a b a d "
// zArray -  0 0 3 0 1 0 5 0 3 0 1 0 3 0 1 0

// Dry Run --->
// At indx 6 --> Range is created --> ( 6, 10 ) --> len = 5
// at indx 8 --> Z[i] = 3 --> Which is Wrong ... It should be 5

// Problem where arise ??
// Actaully the range was fixed at indx 5 i.e l = 6 and r = 10
// so for "a b a b a" , at indx 8, it only considers the elements till indx 10 & hence ans = 3 .. 
// But if we go beyond the boundary, there are 2 characters that are matching and will result in Z value as 5

// SOLUTION ---->
// Expand the Boundary(r) to see more characters matches or not 


// Conclusion ------------------------>>

// Use the past values and Try to increase / decrease the Boundary as per the condition

// In the Algorithm -->
// For any indx, 
// First, if copying make You go beyond the Boundary, then restrict length within the Boundary. After doing this, try to expand Boundary to see
// more charactes are matching or not


// HOW IT HELPS IN PATTERN MATCHING ????
// Keep Your pattern at the starting and add $ after it and then the original string
// $ is just the separator and the end of the pattern...
// Wherever in the Z array , if Z[i] = pattern length, so this are the indexes, where our whole pattern length was match.


// CODE -------------------------------->>

vector<int> zMatch(string s){

    vector<int> z(s.size() , 0);

    // Initial range
    int l = 0, r = 0;

    for(int i = 1; i < s.size(); i++){

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

int main(){

    vector<int> z = zMatch("aba$ababbababaaa");  // aba is pattern

    for(int x : z) cout << x << " ";

    cout << endl;

}


// TIME --->

// For each indx, if you calculate a Boundary, You are not calculating indx within it again, You are depending on the past values..
// During Expansion also, you are expanding for the Boundary beyond indexes.
// Its just like 2 pointers moving forward, Once for range calculating & then moving in that l -> r and using past values






