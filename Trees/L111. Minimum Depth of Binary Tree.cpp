/*
 * Author : Shruti Katyal
 * Date   : 27 January, 2020
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        return 1 + (min(left,right) ? min(left,right) : max(left,right));
    }
};
