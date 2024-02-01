#include<bits/stdc++.h>
using namespace std;

// RECURSION ---------------------------------->>

// TIME - O(2 ^ K)

// DP ?
// No, becz 1 <= n <= 10^5 and aap dp[l][h] ka banaoege --> Memory : 10^5 * 10^5 --> Memory Exceeded

// ONE WAY ------------------------------------>>

// Minimum Subarray Sum ---> 

// We can think this Question in Reverse way, k elements pick krne hai, so Humko n-k size ka Subarray with min_Subarray sum nikalna hai

// NAIVE -> O(n^2)
// BEST -> O(N) [ Sliding Window ]

// ANOTHER WAY ----------------------------------->>>

// Prefix - Suffix array of size k

// TIME - O(k)
// SPACE - O(k)


// SLIDING WINDOW ----------------------------------->>

// Yha pe window of k hai. Lekin yeah window slide starting aur end me honga i.e 
// front - [0 ... k] , back = []
// front - [0 ... k-1] , back = [ n-1 ]
// front - [0 ... k-2] , back = [ n-2 n-1 ]

// OBSERVE, with Sliding Window, We are trying out all possibilties of taking k elements.

// TIME - O(k) 
// SPACE - O(1)
 

int maxScore(vector<int>& arr, int k) {

    int n = arr.size();
    
    int mx = 0;

    int sum = 0;

    for(int i=0;i<k;i++){
        sum += arr[i];
    }

    mx = max(mx, sum);

    for(int i=1;i<=k;i++){

        sum += arr[n - i];
        sum -= arr[k - i];

        mx = max(mx, sum);

    }

    return mx;

}
