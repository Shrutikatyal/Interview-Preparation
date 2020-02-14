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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return NULL;
        
        vector<TreeNode*> stack;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        stack.push_back(root);
        int index = inorder.size()-1;
        
        for(int i=postorder.size()-2;i>=0;i--)
        {
            TreeNode* curr = stack.back();
            if(curr->val != inorder[index]){
                curr->right = new TreeNode(postorder[i]);
                stack.push_back(curr->right);
            }
            else {
                while(!stack.empty() && stack.back()->val == inorder[index]){
                    curr = stack.back();
                    stack.pop_back();
                    index--;
                }
                if(index >= 0){
                    curr->left = new TreeNode(postorder[i]);
                    stack.push_back(curr->left);
                }
            }
            
        }
        return root;
    }
};
