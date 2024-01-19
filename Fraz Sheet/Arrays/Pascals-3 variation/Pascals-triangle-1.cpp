// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// N = 5, r = 5, c = 3
// 6 (for variation 1)

// No need to prepare the Pascals triangle to solve this problem .. There is a Formula to get the element at (r,c)

// FORMULA -> (r-1)C(c-1) ( this is nCr)   [ Remember, For 1 based Indexing ]

// Pascals Traingle 0 based indexing ka hai -> row C col


// NAIVE -> nCr ka formula lagana and factorial of n,r,(n-r) nikalna
// TIME ->  O(n)+O(r)+O(n-r)                
// SPACE -> O(1)


// THIS WAY OF FINDING FACTORIAL IS NEVER RECOMMENDED

// OPTIMAL -> nCr ka modified wala jo (numerator me n decrease r times and denominator me r!)
// TIME -> O(r)
// SPACE -> O(1)


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {

    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    // REMEMBER -> In this, we had intentionally started from r = 1 in denominator becz by doing this, at each time of
    //              dividing, there will be no. in numerator to whom denominator can divide (NO COMPUTATION ERROR)

    return res;
}

int pascalTriangle(int r, int c) {

    int element = nCr(r - 1, c - 1);
    return element;
    
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element << "n";
    return 0;
}
        