#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------------- NAIVE ---------------------------------------------------------------

long long power(int x, int n){

    if(n == 0) return 1;

    long long partial = power(x,n-1);

    return x * partial;

}

// Time -> O(n) & Space -> O(n)


// ----------------------------------------------------- Optimized ---------------------------------------------------------------

long long power(int x, int n){

    if(n == 0) return 1;

    long long temp = power(x, n/2);

    if(n&1){
        return temp*temp*x;
    }
    else{
        return temp*temp;
    }

}

// TIME -> O(log n) & Space -> O(log n)


int main(){

    int x, n;
    cin >> x >> n;

    cout << power(x,n) << endl;

    return 0;

}