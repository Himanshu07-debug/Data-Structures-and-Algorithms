// Logic ban gya tha, Was unable to code -> Bhut Complex kar rha tha.. Always try to make min. change on Your Previous same Q.s code

// Difference between House Robber 1 and House Robber 2 ----

// In this Question, There is a cycle, first house is connected with last house

// So, here first house is adjacent to last house ... Dono ko sath me consider nhi kar sakte koi bhi sum me....


// What we can do is that -->
// Hum House Robber 1 ka hi logic rkhte
// Once hum max_sum (0, n - 2) array ka nikalenge and once hum max_sum (1 , n - 1) ka nikalenge...
// Our answer will be maximum of this 2 calculated value...


#include <bits/stdc++.h> 
using namespace std;

// House Robber 1 logic
long long solve(int n, vector<int>& arr) {

    vector<long long> dp(n, 0);

    dp[0] = arr[0];
    
    for (int i = 1; i < n; i++) {

        long long pick = arr[i];
        if (i > 1) pick += dp[i - 2];

        long long nonPick = dp[i - 1];
        
        dp[i] = max(pick, nonPick);

    }
    
    return dp[n - 1];

}

long long houseRobber(vector<int>& house)
{
    // Write your code here.
    int n = house.size();

    if(n == 1) return house[0];       // edge case ... IMP

    vector<int> temp1, temp2;          // 2 arrays

    for(int i=0;i<n;i++){

        if(i != 0) temp1.push_back(house[i]);

        if(i != n-1) temp2.push_back(house[i]);

    }

    return max(solve(n-1, temp1) , solve(n-1, temp2));

}

// Recursive, Memoization, Space optimization --> Sabke liye sirf upar wla update kro code, niche wale me temp1, temp2 rhnge sabme...

// You can use pointers logic also in Place of temp1, temp2 i.e passing st. pointers.

