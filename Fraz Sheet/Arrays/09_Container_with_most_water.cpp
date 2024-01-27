#include <bits/stdc++.h>
using namespace std;


// IDEA ---------------------------------->>>

// 1. The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller 
// one of first and last line.
// 2. All other containers are less wide and thus would need a higher water level in order to hold more water.
// 3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

// IDEA in more easy way ---------------------------->>

// We know that area = width * length. So increasing the length of line or width between two lines will increase the area.

// If we start with the two extremes of the sequence, i.e the first and last line, we can achieve maximum width.

// But this does not ensure maximum area as it is possible that some pair of lines with a lesser width and much greater length than the extreme 
// lengths can have a greater area.

// So this is obvious that if we decrease the width we need to find such a pair of lines that the length of the shorter line is more than the 
// maximum of the previous pair of lines.

// Going further with the smaller height will not contribute in finding the maximum area. 

int maxArea(vector<int>& arr) {

    int n = arr.size();

    int l = 0 , h = arr.size() - 1;

    int mx = 0;

    while(l < h){

        int d = h - l;

        mx = max(mx, min(arr[h], arr[l]) * d);

        if(arr[l] < arr[h]) l++;
        else if(arr[l] > arr[h]) h--;
        else l++;

    }

    return mx;
        
}