/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/

/*
Approach:

When comparing two ranges,there exists a overlapping for the range of
1.maximum of 1st element of both ranges = low
2. Minimum of 2nd element of both  = high
3. low <=high

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
         vector<vector<int>> ans;
        
        int rowA = 0,rowB = 0,rowAns = 0;
        while(rowA<A.size() && rowB<B.size())
        {
            int low = max(A[rowA][0],B[rowB][0]);
            int high = min(A[rowA][1],B[rowB][1]);
                
            if(low<=high)
            {
                vector<int>temp;
                temp.push_back(low);
                temp.push_back(high);
                ans.push_back(temp);
                //rowAns++;
            }
            if(A[rowA][1]<B[rowB][1])
            {
                rowA++;
            }
            else
                rowB++;
        }
        
        return ans;
    }
};
