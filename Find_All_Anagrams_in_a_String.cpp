/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

/*
Approach :

1. Create and initialize an array (parr) with count of each char in string p. 
   We will create similar array for all the substrings formed from string s in sliding window fashion. 
   If both arrays are equal => both string contains equal count of characters. Hence are anagrams.

2. Create and initialize similar array(sarr) created in step 1 for first substring of size p.size() in s.

3. Check for array equality -> add index 0 to result vector if equal.

4. Traverse the string from index 1. In each step update the sarr (count of characters in current substring) and compare for equality.
  
    1. sarr will be updated for each subtring.

    2. As we are sliding to next window, the first character of previous substring will be removed and new character will be added at the end.
       Update the sarr accordingly
       
    3. Compare parr and sarr, if equal add current index in result.
*/

class Solution {
public:
    bool equalArrays(int* parr,int* sarr)
    {
        for(int i =0;i<26;i++)
        {
            if(parr[i] != sarr[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
      
        vector<int>res;
          if(s=="" || s.size() < p.size())
            return res;

        int parr[26];//vector<int>pvec(26,0);
        int sarr[26];//vector<int>svec(26,0);
        for(int i=0;i<26;i++)
        {
            parr[i] = 0;
            sarr[i] = 0;
        }
        for(int i=0;i<p.size();i++)
        {
            parr[p[i]-'a']++;
            sarr[s[i]-'a']++;
        }

        if(equalArrays(parr,sarr))
            res.push_back(0);
        for(int i=1;i<=s.size()-p.size();i++)
        {
            sarr[s[i-1] -'a']--;
            sarr[s[i + p.size()-1] - 'a']++;
            if(equalArrays(parr,sarr))
                res.push_back(i);
        }
        return res;
    }
   
   /* 
   Initially used vectors pvec and svec instead of arrays parr and sarr
   Array solution is more time efficient 
   
   vector<int> findAnagrams(string s, string p) {
      
        vector<int>res;
          if(s=="" || s.size() < p.size())
            return res;
       
        vector<int>pvec(26,0);
        vector<int>svec(26,0);
          
        for(int i=0;i<p.size();i++)
        {
            pvec[p[i]-'a']++;
            svec[s[i]-'a']++;
        }
        if(pvec==svec)
            res.push_back(0);
        for(int i=1;i<=s.size()-p.size();i++)
        {
            svec[s[i-1] -'a']--;
            svec[s[i + p.size()-1] - 'a']++;
            if(pvec == svec)
                res.push_back(i);
        }
        return res;
    }*/
    
    
    /*
	brute force approach:
	
	Sorted substring in each sliding window and compared with sorted p
	Time limit exceeded.
	
	vector<int> findAnagrams(string s, string p) {
      
        vector<int>res;
          if(s=="" || s.size() < p.size())
            return res;
        sort(p.begin(),p.end());
        for(int i=0;i<=s.size()-p.size();i++)
        {
            string temp = s.substr(i,p.size());
            sort(temp.begin(),temp.end());
            if(temp == p)
                res.push_back(i);
        }
        return res;
    }*/
};
