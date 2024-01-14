// You are given a matrix having ‘N’ rows and ‘M’ columns. Each cell of the matrix can only contain three values as given below:
// -1 -> It denotes a wall or an obstacle
// 0  -> It denotes a gate
// 2^31 - 1 =  2147483647 ( INF ) -> An infinitely large value  denotes the empty room.

// For each empty room (denoted by INF), you have to refill it with the distance to its nearest gate. If none of the gates is reachable 
// from an empty room then the value ‘INF’ will remain as it is.

// Constraints --> 
// 1 <= T <= 50
// 1 <= N <= 10^4  
// 1 <= M <= 10^4
// 1 <= N*M <= 10^4

// INPUT 1 ------------> 
// INF -1
// -1 0
// OUTPUT ->
// INF -1
// -1 0

// INPUT 2 ------------> 
// INF -1 0 INF
// INF INF INF -1
// INF -1 INF -1
// 0 -1 INF INF

// OUTPUT ->
// 3 -1 0 1
// 2 2 1 -1
// 1 -1 2 -1
// 0 -1 3 4


// LOGIC --------------------------------------->>>

// Instead of doing BFS for each INF to get the nearest 0 and making time -> O(n*m) * O(n*m)

// Aaisi Situation bhut baar aayi hai, we will reverse the Idea -->
// Going from all 0's to all INF
// MULTI SOURCE BFS

// Matrix Updation is same as Problem - 04 ..... Humko Update krna hai with the height of the BFS TREE .. i.e the no. of arrows



