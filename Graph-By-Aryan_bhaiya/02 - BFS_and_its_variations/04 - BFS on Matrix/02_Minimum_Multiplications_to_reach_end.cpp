// Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation
//  with 100000 is done to get the new start.
// Your task is to find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, 
// then return -1.

// Input:
// arr[] = {2, 5, 7} ,  start = 3   ,  end = 30
// Output: 2
// Explanation: 
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30
// Therefore, in minimum 2 multiplications we reach the end number


// LOGIC --------------------------------->>>

// Here we are doing mod of 1e5 for each src created. This means src number ranges from 0 to 9999

// src no.s are limited 
// We can consider all this possible nodes as Graph of 1e5 nodes.

// Min. no. of steps is asked --> BFS

// Why not DP ? --> Cycles can formed. x ne call kiya next possible src's ko, kisi path ne wapas x ko as a src call kiya. It will start calculating
// Again


// CODE --> Normal BFS krdo with current src leke.. Agar saare visited ho gye, and answer return hua while loop me, bahar me -1 return..
// Otherwise q.top() ke childs me jaise hi dest, krdo return steps.. Move level by level in BFS traversal.. [ for loop wla ]