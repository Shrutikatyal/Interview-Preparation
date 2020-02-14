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
 
// INTUITIVE APPROACH - O(n^2)
class Solution {
public:
    int height(TreeNode *node) {
        if(!node) return 0;
        return 1 + max(height(node->left),height(node->right));
    }
        
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        leftHt -= rightHt;
        
        return leftHt>=-1 && leftHt <=1 && isBalanced(root->left) && isBalanced(root->right) ; 
    }
};

//Better approach - O(n)
class Solution {
public:
    int height(TreeNode *node) {
        if(!node) return 0;
        int leftHeight = height(node->left);
        if(leftHeight == -1) return -1;
        int rightHeight = height(node->right);
        if(rightHeight == -1) return -1;
        
        if(abs(rightHeight - leftHeight) > 1) return -1;
        
        return max(rightHeight,leftHeight)+1;
    }
        
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
