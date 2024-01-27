#include<bits/stdc++.h>
using namespace std;

// If a similar Pattern Question come, Never try to think for a new code.. 
// Just think what Modification is required on Previous code...

// NAIVE -> O(n^3)

// Optimal -> O(n^2) + 2 pointers [ 3 sum wla ]

// 2 pointers krnge target find krne ke liye and each time closest sum update krnge all possible i, j, k pe...
// Agar Target mil gya, Closest se bhi Closest i.e 0 mil gya, return current wla sum...


int threeSumClosest(vector<int>& arr, int x) {

    int n = arr.size();

    int ans = 1e9;

    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++){

        int j = i+1;
        int k = n-1;

        while(j < k){

            int sum = arr[j] + arr[k] + arr[i];

            if(sum == x) return sum;

            int y = abs(x - sum);

            if(y < abs(ans - x)){
                ans = sum;
            }

            if(sum < x){

                j++;

            }
            else{
                
                k--;

            }

        }

    }

    return ans;
        
}