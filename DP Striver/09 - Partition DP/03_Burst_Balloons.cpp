#include<bits/stdc++.h>
using namespace std;

// Here, Normal Partition like Previous Question kaam nhi krnga.. Becz kth element remove krne le baad both left and right Subarray merge krna 
// hai... Partition is not leading to 2 independent parts

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

// In such type of Merging Question, We can think in the Opposite way -->
// Instead of thinking that ki first Konsa baloon burst honga, we will first try to find that balloon which we will burst last.

// How this will help ???
// Take Example above [3, 1, 5, 8] --> 
// At last, arr = [ 8 ] ,  8 burst ==> 1 * 8 * 1

// At second last, arr = [3, 8] , 3 will be surely multiplied by 8 becz last was 8, second last 3 hai i.e 2 sized array me, surely there will be 
// multiplication between the 2 numbers ===> 1 * 3 * 8

// At third last , arr = [ 3, 5, 8 ] , 5 will surely Multiplied by 3 and 8 kyuki uska order middle me hai 3 and 8 ==> 3 * 5 * 8

// At fourth last , arr = [3, 1,  5, 8] , 1 will be multiplied by 3 and 5 ==> 3 * 1 * 5

// Note: The intuition is to first find the last balloon, then the second last, and so on. This is the sequence we need to follow to solve 
//       this problem.

// Independent Parts ???
// First last one is selected, Usase uske left wale and Right wale array ke ordering me hi rhnge..
// So we can do Partition like Problem - 02
// Here we will add at first and last 1 in nums array


// RECURSION --------------------------------->>>

int maxCoinsHelper(int i, int j, vector<int> &nums) {

    if (i > j) return 0;

    int maxCoins = INT_MIN;
    
    for (int k = i; k <= j; k++) {

        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums) + maxCoinsHelper(k + 1, j, nums);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);

    }
    
    return maxCoins;
}

int maxCoins(vector<int> &nums) {

    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Call the helper function to compute the maximum coins
    return maxCoinsHelper(1, n, nums);

}


// MEMOIZATION ----------------------------->>

int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {

    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int maxCoins = INT_MIN;
    
    for (int k = i; k <= j; k++) {

        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);
        
        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    
    return dp[i][j] = maxCoins;

}

int maxCoins(vector<int> &nums) {

    int n = nums.size();
    
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    
    return maxCoinsHelper(1, n, nums, dp);

}

// TIME --> O(n ^ 3)



// TABULATION ----------------------------->>

int maxCoins(vector<int> &nums) {

    int n = nums.size();
    
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {

            if (i > j) continue;

            int maxi = INT_MIN;
            
            for (int ind = i; ind <= j; ind++) {

                // Calculate the coins obtained by bursting the ind-th balloon last
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                
                // Calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];
                
                // Update the maximum coins
                maxi = max(maxi, coins + remainingCoins);
            }
            
            dp[i][j] = maxi;
        }
    }
    
    return dp[1][n];

}