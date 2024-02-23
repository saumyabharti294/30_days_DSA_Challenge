/*
Example 1:

Input: nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]
Explanation:
1. After trimming to the last digit, nums = ["2","3","1","4"]. The smallest number is 1 at index 2.
2. Trimmed to the last 3 digits, nums is unchanged. The 2nd smallest number is 251 at index 2.
3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4th smallest number is 73.
4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
   Note that the trimmed number "02" is evaluated as 2.
*/




#include <bits/stdc++.h>
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int highest = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string, int>> trimmedNums; 

            for (int j = 0; j < nums.size(); j++) {
                // Calculate the starting position correctly
                int startPos = nums[j].length() - trim;
                string trimmed = nums[j].substr(startPos, trim);
                trimmedNums.push_back({trimmed, j});
            }

            // Sort based on the trimmed strings; if equal, sort by original index
            sort(trimmedNums.begin(), trimmedNums.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            });
            
            // Find the kth smallest trimmed number's original index
            ans.push_back(trimmedNums[highest - 1].second);
        }
        return ans;
    }
};
