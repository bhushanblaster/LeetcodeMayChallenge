/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
*/

/*

Approach : 
Create a vector of size N+1 and initialize with 0.
Traverse all the pairs in trust matrix, for each pair [a,b] where a trusts on b, decrement vector[a] and increment vector[b].
Now, traverse the vector, if the value at an index = N-1, then all others trust on that index and it doesn't trust on anyone else.

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(N==1)
            return N;
        vector<int>track(N+1,0);
        for(int i=0;i<trust.size();i++)
        {
            track[trust[i][0]]--;
            track[trust[i][1]]++;
        }
        for(int i=0;i<N+1;i++)
        {
            if(track[i] == N-1)
                return i;
        }
        return -1;
    }
};
