/*
 * Author : Shruti Katyal
 * Date   : 05 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> robSub(TreeNode* node) {
        if(node==NULL)
            return vector<int>(2,0);
        
        vector<int> left = robSub(node->left);
        vector<int> right = robSub(node->right);   
        
        vector<int> ans(2,0);
        
        //Node not included in solution
        ans[0] = max(left[0],left[1]) + max(right[0],right[1]);
        //Node included in solution
        ans[1] = node->val + left[0] + right[0];
        
        return ans;
    }
    
    int rob(TreeNode* root) {
        vector<int> ans(2,0);
        ans = robSub(root);
        return max(ans[0],ans[1]);
    }
};
