#include<bits/stdc++.h>
using namespace std;

// NAIVE -------------------------------------------->>

// TIME --> O(n^2 * log(unique_pairs))
// SPACE --> O(log(unique_pairs)

// BETTER ----------------------------------------->>

// SORTING and Binary Search. (lower_bound)
// Handling Duplicates - if(arr[i] == arr[i-1]) continue;

int findPairs(vector<int>& arr, int k) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    int cnt = 0;

    for(int i=0;i<n;i++){

        if(i > 0 && arr[i] == arr[i-1]) continue;

        int indx = lower_bound(arr.begin() + i, arr.end() , arr[i] + k) - arr.begin();

        if(indx < n && arr[indx] == arr[i] + k){
            cnt++;
        }

    }

    return cnt;
        
}

// Instead of Lower_bound, You can use pure BS code, 2 pointers,  or map data structure

int findPairs(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end());

    int i = 0, j = 1, count = 0; 

    while (j < nums.size()) {

        int diff = abs(nums[i] - nums[j]);

        if (diff == k) {
            count++; 
            i++, j++; 
            while (j < nums.size() && nums[j] == nums[j - 1]) j++;

        } else if (diff < k) {

            j++;

        } else {

            i++;

        }

        if(i==j){       // if my diff is continously > k, my i will reach to i == j and then diff will be continously 0 --> [1,3,1,5,4]
            j++;
        }

    }

    return count; 

}


// TIME -> O(nlogn)
// SPACE -> O(1)


// If all distinct indices count of pairs is asked, you have to use map data structure -> Sorted with cnt 
// When k == 0, then cnt += m[arr[i]] - 1 , otherwise cnt += m[arr[i + k]]


// OPTIMAL ------------------------->>

// arr[i] + k searching was taking O(logn) , We can use Unordered_map

// Store in map all arr[i] with their freq
// Traverse in unordered_map --> if(k == 0 && p.second > 1  ||  (k  && m.count(p.first + k)) ) cnt++