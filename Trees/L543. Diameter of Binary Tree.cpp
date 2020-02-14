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
    int diameter;
public:
    int depth(TreeNode* node) {
        if(node==NULL)
            return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        diameter = max(diameter,left+right+1);
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 1;
        depth(root);
        return diameter-1;
    }
};
