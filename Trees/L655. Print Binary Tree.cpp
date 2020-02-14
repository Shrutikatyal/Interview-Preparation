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
    int getHeight(TreeNode* node) {
        if(node==NULL)
            return 0;
        return 1 + max(getHeight(node->left),getHeight(node->right));
    }
    
    void fillRes(vector<vector<string>> &res, TreeNode* node, int i, int l, int r){
        if(node==NULL) return;
        res[i][(l+r)/2] = to_string(node->val);
        fillRes(res,node->left,i+1,l,(l+r)/2);
        fillRes(res,node->right,i+1,(l+r+1)/2,r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
            int h = getHeight(root);
            vector<vector<string>> res( h , vector<string>((1<<h)-1));
            fillRes(res,root,0,0,res[0].size());
            return res;
    }
};
