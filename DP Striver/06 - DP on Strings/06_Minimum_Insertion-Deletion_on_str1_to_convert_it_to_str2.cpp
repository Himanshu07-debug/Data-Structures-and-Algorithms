// You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English alphabets only.
// In one operation you can do either of the following on 's1':
// (1) Remove a character from any position in 's1'.
// (2) Add a character to any position in 's1'.
// Find the minimum number of operations required to convert string 's1' into 's2'.


// LOGIC -------------------------------------------->>>

// String s1 --> s2 krna hai....
// For min. steps, we will find the Longest common Subsequence of both string. 
// Pta chale s1 me kitne common characters hai order me.
// If LCS of both string is --> x , then answer ?
// Insertion -> s2.size() - x , Deletion --> s1.size() - x

// TOTAL NUMBER OF OPERATION -->  (s2.size() - x) + (s1.size() - x)  ==> (s1.size() + s2.size()) - 2*x