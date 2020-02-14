/*
 * Author : Shruti Katyal
 * Date   : 28 January, 2020
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
    int tilt;
public:
    int traverse(TreeNode *node){
       if(!node) return 0;
       int left = traverse(node->left);
       int right = traverse(node->right);
       tilt += abs(left - right);
       return left + right + node->val;    
    }
    
    int findTilt(TreeNode* root) {
        tilt = 0;
        traverse(root);
        return tilt;
    }
};
