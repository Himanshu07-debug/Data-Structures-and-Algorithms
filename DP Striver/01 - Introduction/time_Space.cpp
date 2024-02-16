// TIME COMPLEXITY ------------------->>

// 1. If all States have same time   --> no. of States * avg transition time per State  .. ( O(n)  --> O(n) --> O(n) --> .... )

// 2. If all States have varying time ---> Sum of transition time for each state i from 1 to n .. (O(n) --> O(n/2) --> O(n/3) --> .....)


// SPACE COMPLEXITY ------------------->>

// No. of states * Space Complexity of each state


// NOTE For Memoization & Tabulation ======================>>>>

// Memoization ->
// Observe the Changing Parameters in Recursion, DP table unhi se banega

// TABULATION ->
// Reverse the flow of each changing variable.
// Ex - In Memoization, i was moving from 0 -> n-1 ... In Tabulation, Just Reverse it = n-1 to 0

// Space optimization -> 
// What are the other states that my current state is dependent on.

