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
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        
        //if root->val > R then all of the right sub tree will be >R.
        if(root->val > R) return trimBST(root->left,L,R);
        if(root->val < L) return trimBST(root->right,L,R);
        
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
};
