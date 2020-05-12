
/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.Find this single element that appears only once.
 
Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

/*
Binary search with a tweak:

Step 5 below is important which decides in which partition the element is present

binarySearch(nums,start,end)
{

  Get the mid index

  If mid = 0 the check only right element, if they are not same return nums[mid]

  If mid = nums.size()-1 i.e. last index then only check left element, return nums[mid] if not same.

  Else check on right and left of mid, return nums[mid] if not found on either side.

  If conditions 2,3,4 are false, it means the mid element is found on either side.
  {
    Get the counts
    
    left = count numbers on left side of mid including mid
    right = count of numbers on right side
    
    If the element is available on left side
    {
      left includes a pair of nums[mid] element and remaining elements
      if left = odd -> it means the single element is in on left side
      if left = even -> means single element is on right side
       
      call binarySearch recursively by updating start, end index accordingly
    }
    else
    {
      means we had found element on right side
      right contains 1 element of nums[mid] & remaining elements
      if right = even -> the single element is on right side as we have not included mid in right count
      if right = odd -> the single element is on left side.
      
      call binarySearch recursively by updating start, end index accordingly
    }
  }
}
*/
class Solution {
public:
    
    int binarySearch(vector<int>& nums,int start,int end)
    {
        int mid = (start /2)+(end/2) + (start%2 + end%2)/2;
        
        if(mid==0 && nums[mid+1]!=nums[mid])
        {
            return nums[mid];
        }
        else if(mid == nums.size()-1 && nums[mid]!=nums[mid-1])
        {
            return nums[mid];
        }
        else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
        {
            return nums[mid];
        }
        else
        {
            int left = mid+1;
            int right = nums.size()-1-mid;
            if(nums[mid]==nums[mid-1])
            {
                if(left%2 == 1)
                    return binarySearch(nums,start,mid-1);
                else
                    return binarySearch(nums,mid+1,end);
            }
            else
            {
                if(right%2==0)
                    return binarySearch(nums,mid+1,end);
                else
                    return binarySearch(nums,start,mid-1);
            }
        }
            
            
            
    }
    int singleNonDuplicate(vector<int>& nums) {
        int num = nums[0];
        if(nums.size() > 1)
             num = binarySearch(nums,0,nums.size()-1);
        return num;
    }
};
