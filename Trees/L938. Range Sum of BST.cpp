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
    int sum;
public:
    void dfs(TreeNode* node, int left, int right) {
        if(node){
            if(node->val >= left && node->val <= right)
                sum += node->val;
            if(left < node->val)
                dfs(node->left,left,right);
            if(right > node->val)
                dfs(node->right,left,right);
        }    
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        dfs(root,L,R);
        return sum;
    }
};
