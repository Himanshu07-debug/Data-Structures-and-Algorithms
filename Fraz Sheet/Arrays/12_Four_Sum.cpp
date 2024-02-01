//  Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an 
// array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Note:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct. i.e indexes should be distinct..
// arr[a] + arr[b] + arr[c] + arr[d] == target

// arr[] = [1,0,-1,0,-2,2], target = 0
// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Explanation: We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0.
//               The result obtained is such that the sum of the quadruplets yields 0.


// 1 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9


// LOGIC ----------------------------------------------------->>>>

// No need to think for this Question. We will used 3 sum Question Logic and Explanation Flow i.e Approach to solve this Problem in Interview...

// NAIVE -------------------------------------------->>

// 4 loops


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size(); //size of the array

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {

                    // Here Overflow is a Major Issue, So ek-ek krke add krnge... IMP Technique To avoid Overflow
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;

}


// BETTER ------------------------------------------------------>>>

// 3 sum ka Better Appraoch --> Hashset wla

// In 3 sum, hum ek pointer fix krte the.. Yha 2 loop chalake 2 pointer fix krnge... 

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size(); 

    set<vector<int>> st;


    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            set<long long> hashset;

            for (int k = j + 1; k < n; k++) {

                long long sum = nums[i] + nums[j];

                sum += nums[k];

                long long fourth = target - sum;

                if (hashset.find(fourth) != hashset.end()) {

                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    // typecasting of fourth is IMP. Answer is expected in vector<int> , but int is not sufficient to handle the sum part. So
                    // we had taken it long long

                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

// TIME -> O(n^3 * log(no. of unique quadraplets)) 

// SPACE -> 2 * O(no. of unique Quadraplets)  +  O(n) [Internal Hashset]


// OPTIMAL ------------------------------------------------>>

// 3 sum ka 2 pointers appraoch with Duplicate handling.
// 1. Sorted array insert kar rhe the, Hum given array ko sort kar denge to ensure sorted insert vector
// 2. 2 pointers fix and rest 2 se Two pointer technique

// we are not using any extra space, only the space required is to store the answer

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size(); 

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());


    for (int i = 0; i < n; i++) {

        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {

            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;

            while (k < l) {

                // to avoid Overflow
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target) {

                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;

                }
                else if (sum < target) k++;
                else l--;

            }

        }

    }
    

}

// TIME -> O(n ^ 3) + O(nlogn)
// SPACE -> O(1) [ the extra space you are using is to store the answer ]

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}



