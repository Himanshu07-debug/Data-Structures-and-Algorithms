// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

// 1. We can buy and sell the stock any number of times.
// 2. In order to sell the stock, we need to first buy it on the same or any previous day.
// 3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
// 4. We can do at-most K transactions.

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4 - 2 = 2.


// LOGIC ----------------------------------->>>

// Same like prev Best_time - 03 question, only we have capacity of k

