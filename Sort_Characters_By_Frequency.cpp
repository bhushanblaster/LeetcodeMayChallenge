/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

/*
Approach:
1. Create a map<char,int> to store the frequency of each character in the string.
2. Traverse the map till it has 0 size
   1.Get tha character with max frequency.
   2. Add the character for that many times in the string from beginning.    

*/

class Solution {
public:
   
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto ch:s)
        {
            mp[ch]++;
        }
        int index = 0;
        
        
        while(mp.size())
        {
            char nextChar = '\0';
            int maxCount = 0;
            auto it1=mp.begin();
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                if(it->second > maxCount)
                {
                    maxCount = it->second;
                    nextChar = it->first;
                    it1 = it;
                }
            }
            for(int i=0;i<maxCount;i++)
            {
                s[index++] = nextChar;
            }
            mp.erase(it1);
        }
        return s;
        
    }
};
