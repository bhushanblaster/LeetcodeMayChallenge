/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

/*
Solution approach : 

Recursive approach : 
fill the current pixel and check if right,left,top,down pixel has the same color. 
Call fill recursively on that pixel.

Iterative approach: 
Add the initial pixel in queue. 
Perform while queue is not empty ->
1. take out the pixel from queue and fill it. 
2. Check left,right,top,down pixel if it has the same color as original add that pixel in queue.
*/
class Solution {
public:
    void fillImageRec(vector<vector<int>>& image,int x,int y,int origC,int newC)
    {
        image[x][y] = newC;

        //check left
        if(y-1 >= 0 && image[x][y-1]==origC)
            fillImageRec(image,x,y-1,origC,newC);

        //check right
        if((y+1 < image[0].size()) && image[x][y+1] == origC)
             fillImageRec(image,x,y+1,origC,newC);

        //check up
         if(x-1 >= 0 && image[x-1][y]==origC)
            fillImageRec(image,x-1,y,origC,newC);

        //check down
        if((x+1 < image.size()) && image[x+1][y] == origC)
             fillImageRec(image,x+1,y,origC,newC);
        
    }
    void fillImageUsingQ(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int O = image[sr][sc];

        queue<pair<int,int>>q;
        q.push(pair(sr,sc));
        while(!q.empty())
        {
            auto point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;
            image[x][y] = newColor;

            //check left
            if(y-1 >=0 && image[x][y-1] == O)
                q.push(pair(x,y-1));
            //check right
            if((y+1 < image[0].size()) && image[x][y+1] == O)
                q.push(pair(x,y+1));
            //check up
            if(x-1 >=0 && image[x-1][y] == O)
                q.push(pair(x-1,y));
            //check down
            if((x+1 < image.size()) && image[x+1][y] == O)
                q.push(pair(x+1,y));
        } 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) //if this check is omitted it will run forever
        {
             fillImageUsingQ(image,sr,sc,newColor);  // iterative using queue
             //fillImageRec(image,sr,sc,image[sr][sc],newColor); //recursive approach
        }
        return image; 
        
    }
};
