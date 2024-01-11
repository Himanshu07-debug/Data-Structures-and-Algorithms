// All Possible Subsets are together called as Power Sets

// Q.s -> Find all Possible Subsets of an array...

// LOGIC -->

// Let array is a, b, c ..

// REMEMBER, I am Lazy, 
// Think that If somebody returns me all possible subsets of {b, c} , Mai a ko kaise include kru ki all possible subsets mil jaaye ??

// {b, c} -> returns () , (b) , (b, c) , (c)

// Observe -> Inorder to get all 8 possible subsets, Each 4 subsets of {b, c} me apko ek baar a add krna hai and ek baar nhi...

// So, I will make an another copy of {b, c}..
// I will keep copy1 as it is..
// In copy2, I will add a to every returned Subsets


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Subsets(vector<int> &arr, int i){

    if(i == arr.size()){
        return {{}};
    }

    vector<vector<int>> partial = Subsets(arr, i+1);

    vector<vector<int>> ans;

    for(vector<int> x : partial){
        
        vector<int> temp;
        temp.push_back(arr[i]);

        for(int y : x){
            temp.push_back(y);
        }

        ans.push_back(temp);
    }

    for(vector<int> x : partial){
        ans.push_back(x);
    }

    return ans;

}

// First Asking the Recursion and then doing our task lead us to write O(n^2) loop for ordering of the elements in Subsets...




// ------------------------------------- Approach - 2 ----------------------------------------------------


// Hum apna task phle krnge and then Recursion se aage ka subsets banane ke liye khnge... So order will be maintaned..

// RECURSION TREE --> NODE ==> (indx, subsets)

void allSubsets(vector<int> &arr, int i, vector<int> &subsets, vector<vector<int>> &ans){

    if(i == arr.size()){

        ans.push_back(subsets);
        return;

    }


    // Adding element
    subsets.push_back(arr[i]);

    allSubsets(arr, i+1, subsets, ans);

    // Removing the added elements for the next call
    subsets.pop_back();

    allSubsets(arr, i+1, subsets, ans);

}

vector<vector<int>> subsets(vector<int>& arr) {

    vector<vector<int>> ans;

    vector<int> subsets;

    allSubsets(arr, 0, subsets, ans);

    return ans;
        
}


int main(){


    vector<int> arr = {1,2,3};

    vector<vector<int>> naive = Subsets(arr, 0);

    vector<vector<int>> Optimized = subsets(arr);

    return 0;

}

// SPACE --> Height of the Tree ==> O(n)
// TIME --> No. of nodes * transition time --> O(2^n - 1) ==> O(2^n)