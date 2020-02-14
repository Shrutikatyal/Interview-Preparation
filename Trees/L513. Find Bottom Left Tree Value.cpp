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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        else return -1;
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->right)
                q.push(root->right);
            if(root->left)            
                q.push(root->left);
        }
        
        return root->val;
    }
};
