
/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

/*

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

Approach : Brute force

1. Traverse the matrix
2. If the current grid value contains 1, 
   1. Increament the ans count. (ans holds the number of such square.)
   2. Check all possible square matrices that can be formed from this current index as 1st element of the new matrix.
      e.g. In above inout matrix, when we are at matrix[0][1], we will check the posible square matrices that can be formed
            with matrix[0][1] as starting element. Two matrices are possible - > 2*2 and 3*3
        
*/

class Solution {
public:
    
    void findSquares(vector<vector<int>>& matrix,int i,int j,int& ans)
    {
        int rows = matrix.size();//
		int cols = matrix[0].size();

		int currRow = 1, currCol = 1;
		while (true)
		{
			if (i + currRow < rows && j + currCol < cols)
			{
				bool flag = true;
				//bool inside =
					for (int k = i; k <= i + currRow; k++)
					{
						for (int l = j; l <= j + currCol; l++)
						{
							if (matrix[k][l] != 1)
							{
								flag = false;
								break;
							}
						}
						if (!flag)
							break;
					}
				if (!flag)
					break;
				else
				{
					ans++;
					currRow++;
					currCol++;
				}
			}
			else
				break;
		}
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int ans= 0;
        for (int i = 0; i<matrix.size(); i++)
		{
			for (int j = 0; j<matrix[0].size(); j++)
			{
				if (matrix[i][j] == 1)
				{
					ans++;
					findSquares(matrix, i, j, ans);

				}
			}
		}

		return ans;

        
    }
};
