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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL) return t2;
        
        if(t2==NULL) return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
