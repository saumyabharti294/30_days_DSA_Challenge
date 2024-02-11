/*
Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
  
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
*/



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.rbegin(),s.rend());
        sort(g.rbegin(),g.rend());
     int count=0;
     int i=0,j=0;
     while(i<g.size() && j<s.size())
     {
         if(s[j]>=g[i])
         {
         count++;
         j++;
         }
         i++;
     }
     return count;
    }
};
