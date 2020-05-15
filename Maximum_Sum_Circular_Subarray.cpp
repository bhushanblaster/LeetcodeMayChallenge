
/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000

*/

/*
Aproach 1 : Brute force using Kadane's algorithm.

Initially I solved with naive approach.

In that, I applied Kadane's algorithm to all possible arrays formed by rotation and got the maximum sum subarray in each. 
And the maximum among all these max will be the answer.

Time complexity = O(n^2)

The solution was correct but got 'Time limit exceded' for large input array.
*/

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int size = A.size();
		int ans = A[0];
		for (int i = 0; i<size; i++)
		{
			int sum = A[i];
			int cur = sum;
			for (int j = i + 1; j<i + size; j++)     
			{
				cur = cur + A[j%size];     // wrapping around the end of the array
				if (cur<A[j%size])
					cur = A[j%size];

				sum = max(sum, cur);     
			}
			ans = max(sum, ans);      // ans is max of all possible arrays
		}
		return ans;
	}
};


/*
Approach 2: Kadane's algo with some adaptaion

We can get the max sum either in the original array or in the circular array i.e. by wrapping the elements after the end.
For this, we will find max sum in both cases:

To find max sum in original array -> apply Kadane's algo
To find max sum in cicrular array
If we observe the max sum sub array in circular array, we can see that the remaining sub-array is always the minimum sum sub array.
e.g
5 -3 5 => max sub array [5 5]  min sum -> [ -3 ]
3, 4, -6, -5, 2, 7, -1,8 max sub array [3, 4,  2, 7, -1,8] min sum [-6, -5,]
So, in this case we will find the minimum sum sub array instead of max using same algo and subtract it from total sum.
Thus we will get the max sum in circular sub array.

Now, the greater among the two sums(case 1 & 2) will be the answer.

Corner case:
When all the array elements are negative
A = [-1,-2,-3,-4]
max with case 1 => -1
max with case 2 => total - minimum sum = -10 - (-10) = 0

=> when all the numbers are -ve, total and minimum sum will be same and we will always get 0 where as 0 is not there in the array and max sum is -1 which is given by case 1.
The case 1 will evaluate to a -ve number only if all the numbers are -ve.
Hence, when sum returned by case 1 is -ve that is our answer. No need to compare it with 2nd case.
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int size = A.size();
        int maximum = A[0];
        int total = A[0];
        int curMax =A[0];
        int curMin =A[0];
        int minimum = A[0];
        
        for(int i=1;i<size;i++)
        {
            curMax = curMax + A[i];
            curMax = max(curMax,A[i]);
            maximum = max(maximum,curMax);
            
            curMin += A[i]; 
            curMin = min(curMin,A[i]);
            minimum = min(minimum,curMin);
            total+=A[i];
        }
        
        if(maximum>0)
        {
            maximum = maximum>total-minimum?maximum:total-minimum;
        }
            
        return maximum;
    }
};
