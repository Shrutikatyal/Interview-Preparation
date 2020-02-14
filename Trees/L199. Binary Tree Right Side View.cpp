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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        queue<TreeNode*> q;
        
        if(root){
            q.push(root);
            q.push(NULL);
        }
        
        while(!q.empty()){
            
            TreeNode* node = q.front();
            q.pop();

            if(node && node->left) 
                q.push(node->left);
            if(node && node->right)
                q.push(node->right);
            
            if(q.front()==NULL){
                q.pop();
                rightView.push_back(node->val);
                if(!empty(q))
                	q.push(NULL);
            }
                
        }
        
        
        return rightView;
    }
};
