// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
// [1,2,1],
// [2,1,1]]

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10


// Here, there are Duplicates elements in the array..

// So, Slight modification to the permutation code to avoid Duplicates
// Same elements se hi swap kronge to Elements ki arrangement same hi rah jayegi and then uska Call se jitne bhi Permutation banega.. Duplicates
// banega
// 1 1 2 --> i = 1 , pos = 0 ... After swapping.. 1 1 2 --> Jab i=0, tha to iske liye call kiye the

// One more Problem --> [2 2 1 1]
// Jab pos = 1 ko set kar rhe ho to ek hi 1 i.e phle wla hi consider krna padega, Kyuki [2 1 2 1] -> dono possible permutation bna denga jo
// [2 1 1 2] banega
// REASON --> Same pos pe same no. se swap kronge to samne wale i.e [0 .. pos] ka arrangement pichli baar wle same no. jaisa hi rah jayega and 
//            [ pos + 1 .. n-1 ] tk ke bhi elements same hi rah jayenge .. So Inke all possible permutation samne wale ko lagake pichli baar wle
//            ne bna liya honga already


// FINAL CONCLUSION --> For a position, I have to bring only the unique elements to that position from the list of remaining elements( R.H.S )

#include<bits/stdc++.h>
using namespace std;

void permutation(vector<int> &arr, int pos, vector<vector<int>> &ans){

    if(pos == arr.size()){
        ans.push_back(arr);
        return;
    }

    unordered_set<int> s;

    for(int i=pos;i<arr.size();i++){

        // Check for Duplicates
        if(s.count(arr[i])) continue;

        s.insert(arr[i]);

        // fix the ith indx character to the current position
        swap(arr[i], arr[pos]);

        permutation(arr, pos+1, ans);

        // undo the change we had made
        swap(arr[i], arr[pos]);

    }


}

vector<vector<int>> permuteUnique(vector<int>& arr) {

    vector<vector<int>> ans;

    permutation(arr, 0, ans);

    return ans;
        
}