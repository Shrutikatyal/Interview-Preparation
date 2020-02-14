/*
 * Author : Shruti Katyal
 * Date   : 31 January, 2020
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        TreeNode* curr = root;
        
        while(curr || !stack.empty()) {
            while(curr) {
                stack.push_back(curr);
                curr = curr->left;
            }
            
            curr = stack.back();
            stack.pop_back();
            res.push_back(curr->val);
            curr = curr->right;
        }
        
        return res;
    }
};
