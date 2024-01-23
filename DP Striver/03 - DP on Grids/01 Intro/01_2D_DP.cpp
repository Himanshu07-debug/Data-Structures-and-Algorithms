// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. 
// (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills,
//  he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the 
// maximum number of merit points that Ninja can earn.


// n = 3
// matrix below ->
// 1 2 5 
// 3 1 1
// 3 3 3
// Ans -> 11 ( 5 + 3 + 3 )


// LOGIC ----------------------------------------->>>

// How Striver Thought, see ????

// Greedy karna hai, Can you prove ??
// Suppose , day1 -> [ 1 10 5 ] , day2 -> [ 4 100 9 ]
// By Greedy, You will select 10 at day1 jiske wajah se 100 nhi le paonge second me , GREEDY FAIL

// GREEDY fail, means we have to try out all possibilities... RECURSION ...

// What will be the parameters i.e indexes to represent the state ???

// We will move from (n-1) -> 0  ===> Striver Way

// Here, Apko day ka indx rkhna honga, But You will also required to have the info ki previous day me konsa task liye the so that uss task ko 
// na le iss day pe

// Parameters -> (day, last) 

// Stuff that you will do ---->
// For current day, aap wo task select kronge jo task previous day select nhi hue and selected task ko next day ke liye pass kar denge so that 
// wo iss task ko select na kare

// We will make 2 calls from main function, once taking first element as parent, second, third .. 3 calls ke liye O(2^n) * O(3) [loop of task]
// This will give TLE, 3 * O(2^n) , O(2^n)




// Overlapping Subproblems ----> Draw Recursion tree -> Must , issi se click honga


// YES, overlapping Subproblem, Bass laga do DP

// dp[n][4]   ---> task indx = 3, specified, none of the previous task were performed....
// dp[n-1][3] hi to answer chahiye na, starting me hum teeno task se start kar sakte hai... 


// MEMOIZATION ------------------------------------------------------->>>>


#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {

  // If the result for this day and last activity is already calculated, return it
  if (dp[day][last] != -1) return dp[day][last];

  // Base case: When we reach the first day (day == 0)
  if (day == 0) {

    int maxi = 0;

    // Calculate the maximum points for the first day by choosing an activity different from the last one
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }

    // Store the result in dp array and return it
    return dp[day][last] = maxi;

  }

  int maxi = 0;

  // Iterate through the activities for the current day
  for (int i = 0; i <= 2; i++) {

    if (i != last) {
      // Calculate the points for the current activity and add it to the maximum points obtained so far (recursively calculated)
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);

    }

  }

  // Store the result in dp array and return it
  return dp[day][last] = maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points) {

  // Create a memoization table (dp) to store intermediate results
  vector<vector<int>> dp(n, vector<int>(4, -1));

  // Start the recursive calculation from the last day with no previous activity
  return f(n - 1, 3, points, dp);

}

// TIME -> O(n * 4) states * O(3) [loop] 
// SPACE -> O(n * 4) + O(n) [ call stack ]

// Iterative se Call stack nullify krte ....



// ITERATIVE CODE -------------------------------------------------------------->>>

int ninjaTraining(int n, vector<vector<int>>& points) {

  vector<vector<int>> dp(n, vector<int>(4, 0));

  // Day 0
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);

  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // Agar single day tha to answer to yhi jayega

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {

    for (int last = 0; last < 4; last++) {

      dp[day][last] = 0;
      
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {

        if (task != last) {

          int activity = points[day][task] + dp[day - 1][task];

          dp[day][last] = max(dp[day][last], activity);

        }
        
      }

    }

  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];

}

// SPACE --> O(n * 4)


// SPACE OPTIMIZATION ------------------------------------------->>>

int ninjaTraining(int n, vector<vector<int>>& points) {

  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {

    // Create a temporary vector to store the maximum points for the current day's activities
    vector<int> temp(4, 0);

    for (int last = 0; last < 4; last++) {

      temp[last] = 0;

      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {

        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (stored in prev)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }

      }

    }

    // Update prev with the maximum points for the current day
    prev = temp;

  }

  // The maximum points for the last day with any activity can be found in prev[3]
  return prev[3];


}


// SPACE --> O(4)


int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
}







