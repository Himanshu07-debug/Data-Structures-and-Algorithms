#include<bits/stdc++.h>
using namespace std;

// SUBSEQUENCE vs SUBSET -->
// In a SUBSEQUENCE, the elements need to follow the order of the original array whereas
// in a SUBSET there is no constraint on the order of the elements. 
// [1, 2, 5, 4, 3]
// Subset -> [1, 4, 5]
// Subsequence -> [1, 5, 4]


// Order Do not matter, Sort it...
// Now this Question will be reduced to find the Longest Divisible Subsequence where hum LIS ke liye soch sakte hai..

// [1, 4, 8]
// 4 % 1 == 0 , So LIS length = 2
// Now, 8 % 4 == 0, did we have to check for 1 also , NO, as 8 is divisible by 4 and 4 is divisble by 1 i.e 8 is divisble by 1 also..

// NOTE -> As the temp array formed will always be sorted, and arr[i] is divisible by the temp[last], we can say that arr[i] will be 
//          divisible by every element before the temp[last] of the temp array.


// SORT nhi kiye to -> [1, 4, 2, 34] --> Yha pe ans = 3 aana chahiye lekin kyuki 2 tk length 3 hai and 34 divisble hai 2 se, length will +1
// Answer ==> 4 ( WRONG )



vector<int> divisibleSet(vector<int>& arr) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);  // dp[i] stores the length of the divisible subset ending at arr[i]

    vector<int> hash(n); // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++) {

        hash[i] = i; // Initialize with the current index

        for (int prev_index = 0; prev_index < i; prev_index++) {

            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }

        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}