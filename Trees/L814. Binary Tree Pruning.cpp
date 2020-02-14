/*
 * Author : Shruti Katyal
 * Date   : 07 February, 2020
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
    bool containsOne(TreeNode* node) {
        if(node==NULL) return node;
        bool left = containsOne(node->left);
        bool right = containsOne(node->right);
        if(!left) node->left = NULL;
        if(!right) node->right = NULL;
        return node->val || left || right;
    } 
public:
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root)? root : NULL;
    }
};
