// Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero.

// [-1,0,1,2,-1,-4]     -> [[-1,-1,2],[-1,0,1]]
// NOTE -> O/P should have unique triplets, therefore [0,1,-1] is valid but not allowed as we already have [-1,0,1]


// NAIVE -> 3 loops and set to store the unique triplets.. 

// HOW TO HANDLE THE DUPLICATES ? ( Sorted triplets ko add krnge set me )

// Complexitites -> O(N^3 * log(no. of unique triplets) )  && O(2 * no. of the unique triplets) [ set + o/p array ]


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Naive(int n, vector<int> &arr) {

    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());         // ------> O(1) [Sorting only 3 numbers]
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// BETTER ------------------------------------------------------->>

// A + B + C = 0 --->  -A = (B + C)   OR    C = -(A + B)  

// Therefore we will select one number as target and apply Two sum in the rest of the array 


vector<vector<int>> Better(int n, vector<int> &arr) {

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        set<int> hashset;

        // Selecting the target
        int target = -arr[i];

        // Applying Two Sum algo
        for (int j = i + 1; j < n; j++) {

            //Calculate the 3rd element:
            // int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(target-arr[j]) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], target-arr[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);

        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    
    return ans;
}

// Complexitites -> O(N^2 * log(no. of unique triplets) ) & O(2 * no. of the unique triplets) + O[N] ( Extra set)


// OPTIMAL --------------------------------------------------------->>> 

// TIME cant be reduced but Space can, there is no need to have set, hashset if we used Two-pointer Approach
// with initial sorting of array

// HANDLING THE DUPLICATES --> 
// As our array is sorted, same numbers are present in consecutive manner.. If Certain number gives  a valid triplet, 
// we will skip all the consecutive same elements and move our pointer to an different element 


vector<vector<int>> triplet(int n, vector<int> &arr) {

    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;  
        // first time jab same arr[i] encounter hua tha, usase saare jitne possible triplets the bana liye hai 
        // phle hi 2-pointer se

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
                
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// Complexitites -> O(N^2) + O(NlogN) &  O(no. of unique triplets)












