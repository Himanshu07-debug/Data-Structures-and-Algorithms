#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Awesome Technique --> How you nullfiy OR effect from curr OR value while incrementing i
    
int minimumSubarrayLength(vector<int>& arr, int k) {

    int i = 0 , j = 0;

    int mi = 1e9;

    long long brr[31] = {0};

    while(j < arr.size()){

        long long o = 0;

        for(int z = 0; z < 31;z++){

            if(arr[j] & (1ll << z)){
                brr[z] += 1;

            }

            if(brr[z] > 0){
                o += (1ll << z);
            }

        }

        cout << o << endl;

        while(i <= j && o >= k){

            mi = min(mi, j - i + 1);
            
            for(int z = 0; z < 31; z++){

                if(arr[i] & (1ll << z)){
                    brr[z] -= 1;

                    if(brr[z] == 0){
                        o -= (1ll << z);
                    }

                }

            }

            i++;
        }


        j++;

    }

    if(mi == 1e9) return -1;

    return mi;
    
}
