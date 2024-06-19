// What is Partition DP ??

// Whenever we need to find the answer to a large problem such that the problem can be broken into subproblems and the final answer 
// varies due to the order in which the subproblems are solved, we can think in terms of partition DP.

// Problem -> 1 + 2 + 3 * 5
// 1 way -> (1 + 2) + (3 * 5) -> 18
// 2 way -> (1 + 2 + 3) * 5  -> 30


// Problem can be divided into multiple subparts..
// All this subparts are independent and have something value/gain associated with it...
// there is variety of LR dp where subparts are not independent  --> Burst balloons
// Answer differs with the order of solving or dividing the subproblem