#include<bits/stdc++.h>
using namespace std;

// RECURSION ------------------------------>>

int minJump(int i, vector<int> &arr, int n){

    if(i >= n-1) return 0;

    int mi = 1e9;

    for(int j=1;j<=arr[i];j++){

        int z = 1 + minJump(i+j, arr, n);

        mi = min(mi, z);

    }

    return mi;

}

int jump(vector<int>& arr) {

    int n = arr.size();

    return minJump(0, arr, n);

}

// TIME -> Permutation , N Queen wla LOGIC

// Time : O(N!). At each index i we have N-i choices and we recursively explore each of them till end. 
//          So we require O(N * (N-1) * (N-2)...1) = O(N!). 
// Space Complexity : O(N)


// MEMOIZATION ------------------------------------------------>>

int jump(vector<int>& nums) {

	vector<int> dp(size(nums), 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet

	return solve(nums, dp, 0);
}


int solve(vector<int>& nums, vector<int>& dp, int pos) {
    
	if(pos >= size(nums) - 1) return 0;    // when we reach end, return 0 denoting no more jumps required

	if(dp[pos] != 10001) return dp[pos];    // number of jumps from pos to end is already calculated, so just return it

	
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        

	return dp[pos];

}

// TIME -> O(n) * O(n)
// SPACE -> O(n) + O(n)

// TABULATION ---------------------------------------->>

// Agar Recursive chal gya, uska Flow of States copy kro, Logic pe mat jao kaise honga internally Solve States hai, Ensure Flow of States..

int jump(vector<int>& nums) {

	int n = size(nums);

	vector<int> dp(n, 10001);

	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here

	for(int i = n - 2; i >= 0; i--) 

		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 

            if(i + jumpLen < n)  dp[i] = min(dp[i], 1 + dp[i + jumpLen]);  // min(n-1, i + jumpLen) for bounds handling

	return dp[0];
}


// GREEDY BFS ------------------------------------->>>

// 0th index se jump, liye now 0 <= i <= arr[0] range tk maxReach ka Track rkhnge, Jaise hi arr[0] index pe aaye, 0th index ka jump range khatm,
// update the range with arr[0] <= i <= maxReachable, Yha se apko ek aur Jump marna padega

// BFS becz single 0th index se uske possible childs me gye, maxReach index ka Track rkhe and then next jump index ko maxReach se update kiye

int jump(vector<int>& nums) {

	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;

	while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end

		maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level

		if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level

		}            
		i++;

	}

	return jumps;

}

// TIME -> O(n) & O(1) Space

// NOTE: jump^ only gets updated after we iterate all possible jumps from previous level This ensures jumps will only store minimum jump required to reach lastJumpedPos
