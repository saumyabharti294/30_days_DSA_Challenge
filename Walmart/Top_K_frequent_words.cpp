/*
Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
  
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
*/  


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      //step 1: Declaring map to count frequency of each word in vector given
        unordered_map<string,int> mp;
        vector<string> ans;

        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }

       //step 2: Declaring a max heap which is used like a min heap by ushing negative value
        priority_queue<pair<int, string>> topk;
        for(auto it: mp)
        {
            topk.push(make_pair(-it.second,it.first));
            if(topk.size()>k)
              topk.pop();
        }

       //step 3: Declaring a vector to store words to returned in the order they were initially and sort it out according to indices for that
        vector<pair<int,string>> list;
        while(!topk.empty())
        {
            list.push_back(topk.top());
            topk.pop();
        }
        sort(list.begin(),list.end());

       //step 4: Declaring a vector as the return type is a vector of strings
        for(int i=0;i<list.size();i++)
        {
            ans.push_back(list[i].second);
        }

        return ans;
    }
};
