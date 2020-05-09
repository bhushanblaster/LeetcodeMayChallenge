/*Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        bool bRet = false;
        int start = 1;
        int end = num;
        
        while(start <= end)
        {
            int mid = start/2 + end/2 + (start%2 + end%2)/2;
            if(mid>=46341)
            {
                end = mid-1;
            }
            else
            {
                unsigned long long midSquare = mid*mid;

                if(midSquare == num)
                {
                    bRet = true;
                    break;
                }
                else if(midSquare < num)
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        }
        return bRet;
    }
};
/*
Implemented binary search.
The maximum possible input is 2147483647 and the square root of maximum possible perfect square in this range is 46340.
So, while doing binary search, if mid is greater that 46340 adjust the end index.
*/
