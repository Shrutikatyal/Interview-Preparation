/*
 * Author : Shruti Katyal
 * Date   : 29 January, 2020
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
    TreeNode *curr;
public:
    void inorder(TreeNode *node){
        if(node==NULL) return;
        inorder(node->left);
        node->left = NULL;
        curr->right = node;
        curr = node;
        inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        curr = dummy;
        inorder(root);
        return dummy->right;
    }
};
