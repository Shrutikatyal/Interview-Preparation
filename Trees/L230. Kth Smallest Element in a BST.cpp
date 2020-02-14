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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = root;
        stack<TreeNode*> s;
        
        while(1) {
            
            while(temp && k){
                s.push(temp);
                temp = temp->left;
            }
            
            if(s.empty())
                break;
            
            TreeNode* node = s.top();
            s.pop();
            k--;
            if(k==0)
                return node->val;
            
            temp = node->right;
        }
        
        return -1;
    }
};
