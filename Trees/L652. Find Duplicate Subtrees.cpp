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
    unordered_map<string, int> trees;
     vector<TreeNode*> dup;
    
    string serialize(TreeNode* node) {
        if(node==NULL) return "";
        string s = "(" + serialize(node->left) + to_string(node->val) + serialize(node->right) + ")";
        trees[s]++;
        if(trees[s] == 2)
            dup.push_back(node);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return dup;
    }
 
