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
    bool isMirror(TreeNode *p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        return (p->val == q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
         return isMirror(root,root);   
    }
    
};
