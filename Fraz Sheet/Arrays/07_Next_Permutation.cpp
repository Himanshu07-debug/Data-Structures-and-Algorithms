//  Rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest possible order 
// (i.e., sorted in ascending order).


// NAIVE -> Generate all Permutations + Linear search for the I/P permutation + return the next Permutation
//          Time : O (N! * N )

// BETTER -> using STL built-in function  -> O(N)

// OPTIMAL ->  O(N) , without using STL

// OPTIMAL BETTER OBSERVATION ->> https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/


#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {

    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point

    for (int i = n - 2; i >= 0; i--) {

        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }

    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}
