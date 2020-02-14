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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> trav;
        queue<TreeNode*> que;
        int i=0;
        
        if(root) 
            que.push(root);
        while(!que.empty()){
            trav.push_back({});    
            queue<TreeNode*> temp;
            
            while(!que.empty()){
                TreeNode* node = que.front();
                que.pop();
                trav[i].push_back(node->val);
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
            que = temp; 
            i++;
        }
        
        return trav;
    }
};
