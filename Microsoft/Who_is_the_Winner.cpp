/*
Example 1:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
*/



class Solution {
public:
    int findTheWinner(int n, int k) {
        //Time Complexity-->O(n)
        //Space COmplexity-->O(n)
        
        vector<int> ans;
        
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i);
        }

        int j=0;
         while(n>1)
        {
           
            j=j+k-1;
            //if j becomes greater than the people left then we need to reduce it 
            if(j>=n) j=j%n;
            ans.erase(ans.begin()+j);
            n--;
        }

        return ans[0];
    }
};
