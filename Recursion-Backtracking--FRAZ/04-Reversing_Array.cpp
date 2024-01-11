// In Recursion, do small work and Be Lazy... Khud jyada kaam mat kro..

// Aapko array ko reverse krne ko kha hai, Agar merko koi l+1 se r-1 tk reverse krke dede to mai first and last element ko reverse kar dunga
// and answer dunga..

// NOTE --> Think About Subproblems and Be lazy..

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int l, int r){

    if(l >= r) return;

    swap(arr[l], arr[r]);   // -> line 2

    reverse(arr, l+1, r-1); // -> line 3

}

// Follow - up Question ======>
// If You swap line 2 and 3, Any change ??
// No, Answer will be RIGHT... 
// In our Function, We are doing our small task and asking Recursion for the rest of the part... 
// But if we swap, we are saying, Recursion first you do your work, then I will do..

int main(){

    int n; 
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    reverse(arr, 0 , n-1);

    for(int x : arr){
        cout << x << " ";
    }

    return 0;

}