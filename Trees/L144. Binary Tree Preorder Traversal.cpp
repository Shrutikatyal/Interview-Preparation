/*
 * Author : Shruti Katyal
 * Date   : 04 February, 2020
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> trav;
        TreeNode* node = root;
        while(1){

            while(node){
                trav.push_back(node->val);            
                stack.push_back(node);
                node = node->left;
            }
            
            if(stack.empty())
                break;
            node = stack.back();
            stack.pop_back();
            node = node->right;
        }
        
        return trav;
    }
};
