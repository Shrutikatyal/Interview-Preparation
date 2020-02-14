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
    int count;
public:
    int longestUnivalPath(TreeNode* node){
        if(node == NULL) return 0;
        int left = longestUnivalPath(node->left);
        int right = longestUnivalPath(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if(node->left && node->left->val == node->val)
            arrowLeft += left + 1;
        
        if(node->right && node->right->val == node->val)
            arrowRight += right + 1;
        count = max(count,arrowLeft + arrowRight);
        return max(arrowLeft,arrowRight);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        count = 0;
        longestUnivalPath(root);
        return count;
    }
};
