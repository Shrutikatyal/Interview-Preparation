/*
 * Author : Shruti Katyal
 * Date   : 27 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 #include<math.h>
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
    int depth(TreeNode* node) {
        if(!node) return 0;
        
        return 1 + max(depth(node->left),depth(node->right));
    }
    
    void levelOrder(TreeNode *node, unsigned int depth,vector<vector<int>> &traversal) {
        if(!node) return;
        traversal[depth].push_back(node->val);
        levelOrder(node->left,depth - 1, traversal);
        levelOrder(node->right,depth - 1, traversal);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        unsigned int d = depth(root);
        vector<vector<int>> traversal(d,vector<int> {});
        levelOrder(root,d-1,traversal);
        return traversal;
        
    }
};
