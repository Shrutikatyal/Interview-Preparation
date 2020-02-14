/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* parent = root;
        TreeNode* temp = root;
        while(root){
            
            parent = root;
            if(root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        
        if(parent->val > val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);
        
        return temp;
    }
};
