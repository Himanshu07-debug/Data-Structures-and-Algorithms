// A computer Screen can be seen as a Group of pixels... 
// EX => MS paint, Images 

// Wo MS paint, drop rhta tha jiska color drop krne pe ek area me pura fill ho jta tha, This is FLOOD - FILL


// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as 
// the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
// Return the modified image after performing the flood fill.

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]


// Here, Apko (sr, sc) wale cell se chalu krna hai color fill krna... color diya hai ki konsa color fill krna hai...
// All adjacent cell to the Current cell are considered empty if they have the oldColor value ( Jha se fill krna start kiye the )


#include<bits/stdc++.h>
using namespace std;


void flood(int i, int j, vector<vector<int>>& image, int oldColor, int newColor, int n, int m){

    // Boundary Condition
    if(i < 0 || j < 0 || i == n || j == m) return;

    // Iss cell ko fill nhi kar sakte
    if(image[i][j] != oldColor) return ;

    // Putting the new color
    image[i][j] = newColor;

    // All 4 side call
    flood(i+1, j, image, oldColor, newColor, n, m);
    flood(i-1, j, image, oldColor, newColor, n, m);
    flood(i, j+1, image, oldColor, newColor, n, m);
    flood(i, j-1, image, oldColor, newColor, n, m);

}



vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {

    int oldColor = image[x][y];

    // Agar oldColor == newColor rha to, 2 adjacent cell with image[i][j] = oldColor infinetly ek-dusre ko recursive call krnge...
    if(oldColor == newColor) return image;

    int n = image.size(), m = image[0].size();

    flood(x, y, image, oldColor, newColor, n, m);

    return image;
        
}


// TIME --> In worst Case, Hume Saare n*m cells ko fill krna pade.. O(n * m) ... [ Starting Call se hi Pure Cell me chale gaye, starting call ke 
//                                                                                 baaki call revert ]

// SPACE --> In the worst case, O(n * m) extra space is required by the recursion stack