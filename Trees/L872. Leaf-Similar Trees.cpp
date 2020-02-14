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
    vector<int> leaves1, leaves2;
public:
    void recordLeaves(TreeNode* node, vector<int> &leaves){
        if(node==NULL) return ;
        if(!node->left && !node->right) {leaves.push_back(node->val); return;}
        recordLeaves(node->left,leaves);
        recordLeaves(node->right,leaves);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        recordLeaves(root1,leaves1);
        recordLeaves(root2,leaves2);
        return leaves1==leaves2;
    }
    
};
