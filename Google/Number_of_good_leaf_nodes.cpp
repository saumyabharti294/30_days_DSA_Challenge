/*
Example 1:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int ans = 0;
    vector<int> traverse(TreeNode* root, int &distance){
        vector<int>c(distance,0);
        if(!root){
            c[0] = 1;
            return c;
        }
        vector<int>l = traverse(root->left, distance), r = traverse(root->right, distance);
        for(int d1 = 1; d1 < distance; d1++){
            for(int d2 = 1; d2 < distance; d2++){
                if(d1 + d2 <= distance){
                    ans += l[d1] * r[d2];
                }
            }
        }
        for(int i = distance-2; i >= 0; i--){
            c[i+1] = l[i] + r[i]; 
            if(i == 0){
                c[i+1] = max(c[i+1]-1,0);
            }
        }
        return c;
    }
    int countPairs(TreeNode* root, int distance) {
        ios_base::sync_with_stdio(0);
        traverse(root, distance);
        return ans;
    }
};
