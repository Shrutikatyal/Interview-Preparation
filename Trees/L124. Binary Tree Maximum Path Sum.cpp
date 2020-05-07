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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum;
public:
    int findPathSum(TreeNode* node){
        if(node == NULL)
            return 0;
        
        int left = max(findPathSum(node->left),0);
        int right = max(findPathSum(node->right),0);
        maxSum = max(maxSum, left + right + node->val);
        
        return max(left,right)+ node->val;
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        findPathSum(root);
        return maxSum;
    }
};
