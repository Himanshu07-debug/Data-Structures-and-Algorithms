#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



// In the Previous Problem no. - 04 ->
// Space Complexity --> O(n * x)  where 1 <= n <= 100,  1 <= x <= 10^6
// Observation => 10^8 is a huge Space that is Consumed.. To avoid this, Space Optimization in DP came .....


// To Space Optmized any DP problem, ask this 2 question to yourself -->
// 1. What other States Does our Current state depend on ?
// 2. Do we need the answers of every single states to calculate the answer for Your current state or You need answers of some previous states ?



// Examples --->

// 1. Fibonacci Problem ---------------------------->

// dp[i] = dp[i-1] + dp[i-2]

// Observe -> Each state depend only on its immediate previous 2 states answers

// Instead of taking a full prev vector, we will use 2 variables for previous 2 states and will update them progressively

void fib(){

    int n; cin >> n;

    int prev1 = 1, prev2 = 1;  // dp[1] , dp[2]

    for(int i=3;i<=n;i++){

        int curr = prev1 + prev2;
        // dp[i] = dp[i-1] + dp[i-2]

        prev2 = prev1;  // prev2 = dp[i-1]
        prev1 = curr;   // prev1 = dp[i]

    }

    cout << prev1 << endl;

}



// 2. Problem - 01 ---->

// dp[i] = sum of all dp[i-k]  .. ( 1 <= k <= 6)

// Observe -> Each state depend only on its immediate previous 6 states answers

// We will maintain a vector that will keep track of previous 6 states

void dice_Combination(){

    int n; cin >> n;

    vector<int> prev = {1};  // dp[0]

    for(int i=1;i<=n;i++){

        int curr = 0;  // dp[i]

        // dp[i] -> Summation of all the previous 6 states for n >= 6 and less than 6 for n < 6

        for(int j : prev){
            curr = (curr + j)%MOD;
        }

        prev.push_back(curr);

        // if prev contains more than 6 elements info, discard the first element
        if(prev.size() > 6){
            prev.erase(prev.begin());  
        }

    }

    // finally the last element of prev would be dp[n]
    cout << prev.back() << endl;

}

// 3. Problem - 04 ---->>

// dp[i][k] --> no. of ways to get a sum of k such that all coins from c[i] to c[n] are pickable and all coins before c[i] are non-pickable

// dp[i][k] --> dp[i + 1][k]  +  dp[i][k - c[i]]
// Observe -> Each dp[i][k] is dependant on its next row state and current row previous values (like prefix)

// So we can Keep track of next row to get the answer for the current row

void Combination2(){

    int n, x;  cin >> n >> x;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    // vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    vector<int> nextState(x+1, 0);   // dp[n][k]

    nextState[0] = 1; // dp[n][0] = 1;

    // Base case 
    // for(int i=0;i<n;i++){
    //     dp[i][0] = 1;
    // }


    for(int i=n-1;i>=0;i--){

        vector<int> currentState(x+1, 0);   // dp[i][k]
        
        currentState[0] = 1;   // dp[i][0] = 1 ... Will be required in prefix of current row

        for(int sum = 1; sum <= x ; sum++){

            int skip = nextState[sum];
            int pick = 0;
            if(sum - arr[i] >= 0){
                pick = currentState[sum - arr[i]];
            }

            currentState[sum] = ( pick + skip )%MOD;

        }

        // currentState[k] = dp[i][k];
        // nextState[k] = dp[i+1][k];

        nextState = currentState;

    }

    cout << nextState[x] << endl;


}

// for Bottom-up, prepare dp[0][k] as nextState where dp[0][0] = 1;




// 4. A GRID ---->

// dp[i][j] = min( dp[i-1][j] , dp[i][j-1] );

// Observe --> Each row is dependant on its immediate previous row answers

// Keep track of previous row for the current row


 


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    fib();
    dice_Combination();
    Combination2();
    

    return 0;
}