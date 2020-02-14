/*
 * Author : Shruti Katyal
 * Date   : 31 January, 2020
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        
        vector<TreeNode*> stack;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push_back(root);
        int index = 0;
        
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode* curr = stack.back();
            if(curr->val != inorder[index]){
                curr->left = new TreeNode(preorder[i]);
                stack.push_back(curr->left);
            }
            else {
                while(!stack.empty() && stack.back()->val == inorder[index]){
                    curr = stack.back();
                    stack.pop_back();
                    index++;
                }
                if(index < inorder.size()){
                    curr->right = new TreeNode(preorder[i]);
                    stack.push_back(curr->right);
                }
            }
            
        }
        return root;
    }
};
