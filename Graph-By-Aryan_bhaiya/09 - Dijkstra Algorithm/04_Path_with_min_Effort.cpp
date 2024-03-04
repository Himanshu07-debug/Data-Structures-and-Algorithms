// Difference between any 2 adjacent nodes can be considered as Edges in this Question.

// EFFORT OF A PATH ---> max of all abs diff in the path 

// Edges are Weighted and have diff value --> Dijkstra Algo

// How we are sure that ki first time pe jo dest ki dist[] value aayi wo path min. max Absolute diff ka hai ???
// Becz all the other nodes present in the PQ will be of > maxAbs of dist , that's why dest node is at the top of PQ
// So in all other path generated by below nodes in PQ , maxAbs will be definetly >= their curr maxAbs value & top ka maxAbs is min from them all

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int MinimumEffort(vector<vector<int>> &heights)
    {

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell, return the current value of difference (which will be min).
            if (row == n - 1 && col == m - 1)
                return diff;
           
            for (int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // Effort calculation
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }

        return 0; 
        
    }
};

// TIME --> O(n * m * 4  * log(n * m))

// SPACE --> O(n * m)