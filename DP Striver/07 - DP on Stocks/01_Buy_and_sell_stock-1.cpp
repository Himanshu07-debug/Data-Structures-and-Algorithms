#include<bits/stdc++.h>
using namespace std;

// NAIVE --> O(n^2)

// OPTIMAL -->

// We need to find the maximum profit. In order to maximize the profit, we need to buy the stock at its lowest price and sell it 
// when the price is highest.

// To find the individual maximum profit on a day ‘i’, we know the selling price, i.e the price of the stock on day i, we need to find the 
// buying price. To maximize the profit on day ‘i’, the buying price should be the lowest price of the stock from day 0 to day i.

// Therefore, I can say, for every day, I have to keep track of the minimal price day in the past.

int maxProfit(vector<int>& arr) {

    int n = arr.size();

    int mi = arr[0];

    int maxProfit = 0;

    for(int i=1;i<n;i++){

        int currProfit = arr[i] - mi;

        maxProfit = max(maxProfit, currProfit);

        mi = min(mi, arr[i]);

    }

    return maxProfit;
        
}

