/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string. 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

/*
  Aproach:
  It will same as mentioned in Find_All_Anagrams_in_a_String.cpp.
  Maintain two arrays of size 26 and update the second array while sliding.
  Check equality of arrays,return true if equal.
  Return false when traversal completes.
*/

class Solution {
public:
    bool CheckIfArraysEqual(int *arrS1,int* arrS2)
    {
        for(int i=0;i<26;i++)
        {
            if(arrS1[i]!=arrS2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1=="")
            return true;
        if(s1.size()>s2.size())
            return false;
        int arrS1[26],arrS2[26];
        for(int i = 0;i<26;i++)
        {
            arrS1[i] = 0;
            arrS2[i] = 0;
        }
        for(int i=0;i<s1.size();i++)
        {
            arrS1[s1[i]-'a']++;
        }
        for(int i = 0;i<s1.size();i++)
        {
            arrS2[s2[i]-'a']++;
        }
        if(CheckIfArraysEqual(arrS1,arrS2))
            return true;
        for(int i = 1;i<=s2.size()-s1.size();i++)
        {
            arrS2[s2[i-1]-'a']--;
            arrS2[s2[i+s1.size()-1] - 'a']++;
            if(CheckIfArraysEqual(arrS1,arrS2))
                return true;
        }
        return false;
    }
};
