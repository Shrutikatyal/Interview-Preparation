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
    TreeNode *prev;
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
