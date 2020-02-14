/*
 * Author : Shruti Katyal
 * Date   : 30 January, 2020
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
    TreeNode* prev;
public:
    bool IsUnivalTree(TreeNode* node) {
        if(node==NULL) return true;
        
        return prev->val==node->val && IsUnivalTree(node->left) && IsUnivalTree(node->right);
    } 
    
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        
        prev = root;
        return IsUnivalTree(root);
    }
};
