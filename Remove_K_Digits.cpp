/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
Approach:

I will start with an example.

for ex.

num = 142532 k = 1

As k = 1, we have to remove one digit.
Now, we can remove any digit from num but the remaining number should smallest.

In any number the left digits are more significant digits compared to right digits. So we will try to remove the digits from left.
We cannot start removing the digits from left directly as removing 1 from left gives us 42532 which is certainly not the smallest possible number.

If we remove the leftmost digit and the digit next to it is larger than the removed digit then the number we get will not be the smallest
Here leftmost is 1 and 4 is next to it.

But if the number next to it has been smaller, then we had definitely got the smallest number
for ex. instead of 142532 if num was 642532, removing 6 would have given us the smallest number.

hence, our approach will be,

Start from left
If the next digit is smaller than current remove current digit
Now suppose we didn't find any number smaller than current, that means the digits are sorted
Ex. num = 2456789
In this if we want to remove digits, we have to remove the rightmost digit.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size()<=k)
            return "0";
        string ret = num;
        int del = k;
		for (int j = 0; j < k; j++)
		{
			for (int i = 0; i < ret.size() - 1; i++)
			{
				if (ret[i] > ret[i + 1])   //check if current digit is greater than next
				{
					ret.erase(i, 1);    // if true remove that digit
					del--;          // update count of digits to be removed
					break;
				}
			}
		}
		if (del >= 1)  // there are still some digits need to removed - remove rightmost digits
		{
            int index = ret.size()-del;
			ret.erase(index,del);
		}
        ret.erase(0, ret.find_first_not_of('0'));  // removed leading 0's
		if(ret.size()==0)
            return "0";
        
		return ret;
    }
};
