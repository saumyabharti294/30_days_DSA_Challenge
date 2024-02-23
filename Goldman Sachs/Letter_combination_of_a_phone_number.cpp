/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/


class Solution {
     vector<string> ans;
     unordered_map<int,string> m;
    void substringss(string& s1,int start,string& dig)
    {   //int start=0;
        
        if(start==dig.length())
        ans.push_back(s1);

        for(auto x:m[dig[start]-'0'])
        {
            s1.push_back(x);
            substringss(s1,start+1,dig);
            s1.pop_back();
        }
       
    }
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits=="")
        return ans;

        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";

        string s1;

        substringss(s1,0,digits);

        return ans;

    }
};
