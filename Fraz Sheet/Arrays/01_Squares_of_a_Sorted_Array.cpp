#include<bits/stdc++.h>
using namespace std;


// NAIVE -------------------------> sort()

vector<int> sortedSquares(vector<int>& a) {

    vector<int> ans = a;

    for (auto &x : ans) x *= x;

    sort(ans.begin(), ans.end());
    
    return ans;
}

// If input ko change allowed -> O(1) space



// Better -------------------------->> 

// Counting Sort (abs values ko consider krna hai, so max_arr[i] <= 10^4 )

// O(n) , O(10^4)

vector<int> sortedSquares(vector<int>& a) {

    int j = 0, m = 0;

    for (auto &x : a) x = abs(x), m = max(m, x);

    vector <int> c(m + 1, 0);

    for (auto &x : a) c[x]++; 

    for (int i = 0; i <= m; i++) 

        while (c[i]--) 
            a[j++] = i * i;
    
    return a;
}


// Optimized -------------->>

// Two pointers

vector<int> sortedSquares(vector<int>& arr) {

    int n = arr.size();
    vector<int> res(n);

    int l=0, r = n-1;
    int k = n-1;

    while(l <= r){

        int x = abs(arr[l]);
        int y = abs(arr[r]);

        if(x >= y){
            res[k] = x;
            l++;
        }
        else{
            res[k] = y;
            r--;
        }

        k--;
        

    }

    for(int &x : res) x = x*x;

    return res;
    
}


