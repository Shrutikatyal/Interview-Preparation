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
public:
    int rootToLeaf(TreeNode* node, int no) {
        if(node==NULL){ 
            return 0;
        }
        no = no * 2 + node->val;
        return ((node->left==node->right)? no : rootToLeaf(node->left, no) + rootToLeaf(node->right,no));
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return rootToLeaf(root,0);    
    }
};
