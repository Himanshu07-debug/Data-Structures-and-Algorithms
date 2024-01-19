// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// N = 5, r = 5, c = 3
// 1 4 6 4 1 (for variation 2)

// NAIVE ---------------------------------------------------->
//  In nth row, there will be n elements. So hum nth row ke saare elements formula se nikal sakte hai...
//  Interviewer HAAPY nhi honga iss solution se, khnga har element ke liye baar-baar nCr wala formula call
//  kar rhe ho
// TIME -> O(n * r) [nth row and r columns] && O(1) 


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void NAIVE(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}


// OPTIMAL ----------------------------------------->>>> 

// In each row, you can observe that next element in a row can be find by its previous element in the row

// Eg -> 6th row is -> 1 5 10 10 5 1
//       col = 1, 5C1 i.e 5/1 = 5
//       col = 2, 5C2 i.e 5*4/2*1 which is nothing but 5C1 * 4/2 .... Same pattern you can see for further elements

// Therefore, previous answer * (n - col)/ col

// TIME -> O(n) + O(1)

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}


