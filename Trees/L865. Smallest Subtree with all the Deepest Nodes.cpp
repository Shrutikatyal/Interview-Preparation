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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Result{
    public:
        TreeNode* node;
        int dist;
        Result(TreeNode* n, int d) {
            node = n;
            dist = d;
        }
};

class Solution {
    Result* dfs(TreeNode* node) {
        if(node==NULL)
            return new Result(NULL,0);
        Result* left = dfs(node->left);
        Result* right = dfs(node->right);
        
        if(left->dist > right->dist)
            return new Result(left->node,left->dist + 1);
        if(left->dist < right->dist)
            return new Result(right->node,right->dist + 1);
        
        return new Result(node,left->dist + 1);
        
    }  
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root)->node;
    }
};
