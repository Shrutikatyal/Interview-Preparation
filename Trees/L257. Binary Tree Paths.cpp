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
class Solution {
    vector<string> paths;
public:
    void binaryTreePaths(TreeNode* root, string path){
        if(!root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        
        if(root->left) binaryTreePaths(root->left, path + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(root->right, path + "->" + to_string(root->right->val));
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return paths;
        binaryTreePaths(root,to_string(root->val));
        return paths;
    }
};
