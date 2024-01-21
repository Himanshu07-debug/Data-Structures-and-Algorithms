#include<bits/stdc++.h>
using namespace std;

// BETTER -------------------------->>

vector<int> productExceptSelf(vector<int>& arr) {

    int n = arr.size();

    vector<int> pref(n) , suff(n);

    pref[0] = arr[0];
    suff[n-1] = arr[n-1];

    for(int i=1;i<n;i++){

        pref[i] = pref[i-1] * arr[i];

    }

    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1] * arr[i];
    }

    vector<int> ans;

    for(int i=0;i<n;i++){

        int p = 1, s = 1;

        if(i - 1 >= 0) p = pref[i-1];
        if(i+1 < n) s = suff[i+1];

        ans.push_back(p * s);

    }

    return ans;

}


// BEST ----------------------------->>

// No need to have array for Prefix product and Suffix product... We will do it on Runtime on our final array
// First final array ke rach element ko uske respective left se product krnge and Then again traverse krke Right walo se krnge

vector<int> productExceptSelf(vector<int>& arr) {

    int n = arr.size();

    vector<int> ans(n,1);

    int curr = 1;

    // Handling left part for each index
    for(int i=0;i<n;i++){

        ans[i] = ans[i] * curr;
        curr *= arr[i];

    }

    // Handling Right part
    curr = 1;

    for(int i=n-1;i>=0;i--){

        ans[i] = ans[i] * curr;
        curr *= arr[i];

    }

    return ans;

}