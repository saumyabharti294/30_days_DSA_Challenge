/*
Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/



class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }

        vector<pair<char,int>> st;
        for(auto it:mp)
        {
            st.push_back(make_pair(it.first,it.second));
        }
        // Sort by frequency in descending order
        sort(st.begin(), st.end(), [](const pair<char,int> &a, const pair<char,int> &b) {
            return a.second > b.second; // Use frequency to sort in descending order
        });

        string ans;
        for(auto it:st)
        {
            for(int i=0;i<it.second;i++)
            ans.push_back(it.first);

            
        }
        return ans;
    }
};
