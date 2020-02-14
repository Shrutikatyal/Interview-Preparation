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
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }
};


//INORDER APPROACH

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
    
    bool isValidBST(TreeNode* root) {
        long long int inorder = LONG_MIN;
        vector<TreeNode*> stack;
        TreeNode* curr = root;

        while(curr || !stack.empty()){
            while(curr){
                stack.push_back(curr);
                curr = curr->left;
            }
            
            curr = stack.front(); 
            stack.pop_back();
            if(inorder >= curr->val)
                return false;
            inorder = curr->val;
            curr = curr->right;
        }
        
        return true;
    }
};
