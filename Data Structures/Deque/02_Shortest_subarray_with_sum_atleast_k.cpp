#include<bits/stdc++.h>
using namespace std;


int shortestSubarray(vector<int>& arr, int k) {

    int n = arr.size();

    int ans = INT_MAX , sum = 0;

    int i=0, j=0;

    while(j < n){

        sum += arr[j];

        while( i <= j && sum >= k){
            ans = min(ans, j - i + 1);
            sum -= arr[i];
            i++;
        }

        j++;

    }

    return ans;

}

