#include<bits/stdc++.h>
using namespace std;

// 2 sum jaisa hai, lekin 2 sum Sort wla nhi kar sakte .. Pair of (i,j) where i < j is asked

// Also, 2 sum jaisa yha pe koi target nhi, Hashmap/Hashset me kya search kronge... 
// We want (arr[i] + arr[j]) % 60 ... So we will insert remainders in our Hashmap

// NAIVE --->> Use Hashmap  , O(n) + O(n)

// OPTIMAL ---> Use vector 61 size ka  ,  O(n) + O(61)

int numPairsDivisibleBy60(vector<int>& time) {

    int n = time.size();

    // unordered_map<int,int> m;

    vector<int> arr(61 , 0);

    int res = 0;

    for(int i=0;i<n;i++){

        int rem = time[i] % 60;

        // if(m.find(60 - rem) != m.end()){
        //     res += m[60 - rem];
        // }

        // if(rem == 0) rem = 60;    

        // m[rem]++;

        res += arr[60 - rem];

        if(rem == 0) rem = 60;

        arr[rem]++;

    }

    return res;
        
}

// If You are asked to remove the rem = 60 if statement and said to make array of only size 60, having rem -> 0 to 59..
// then when arr[i] is divisible by 60, then only we have problem, So add arr[ (60 - ( rem % 60 )) % 60 ] . Add one more modulo.. 