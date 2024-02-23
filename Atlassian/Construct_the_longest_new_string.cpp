/*
Example 1:

Input: x = 2, y = 5, z = 1
Output: 12
Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
That string has length 12, and we can show that it is impossible to construct a string of longer length.
*/



class Solution {
public:
    int longestString(int x, int y, int z) {
        string ans="";

        for(int i=0;i<z;i++)
        {
            ans+="AB";
        }

        if(x!=0 && y!=0)
        {
            while(x && y)
            {
                ans+="AA";
                x--;
                ans+="BB";
                y--;
            }
            if(y || x)
            return ans.length()+2;

            return ans.length();
        }

        else
        {
            return ans.length()+2;
        }

    }
};
