#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

// Write a function for common code to get max difference in horizontal and vertical array

int maxArea(int h, int w, vector<int>& horizontalCuts , vector<int>& verticalCuts) {

    int n = horizontalCuts.size() , m = verticalCuts.size();

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int max_height = horizontalCuts[0];
    int max_width = verticalCuts[0];

    for(int i=1;i<n;i++){

        int h = horizontalCuts[i] - horizontalCuts[i-1];

        max_height = max(max_height, h);

    }

    for(int i=1;i<m;i++){

        int w = verticalCuts[i] - verticalCuts[i-1];

        max_width = max(max_width, w);

    }

    max_height = max(max_height, h - horizontalCuts.back());
    max_width = max(max_width, w - verticalCuts.back());

    long long ans = 1ll * max_height * max_width;

    return ans % MOD;
        
}