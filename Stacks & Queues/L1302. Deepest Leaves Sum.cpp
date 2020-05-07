/*
 * Author : Shruti Katyal
 * Date   : 6 May, 2020
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
            q.push(NULL);
        }
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node == NULL){
                if(!q.empty()){
                    q.push(NULL);
                    sum = 0;
                }
            }
            else
            {
                sum += node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
        }
        
        return sum;
    }
};
