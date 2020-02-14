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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> max;
        
        if(root) {
            q.push(root);
            q.push(NULL);
        }
        int maxValInRow = INT_MIN;
        
        while(!q.empty()) {
            root = q.front();
            q.pop();
            
            if(root==NULL) {
                max.push_back(maxValInRow);
                maxValInRow = INT_MIN;
                if(q.size())
                    q.push(NULL);
            }
            else {
                if(root->val > maxValInRow)
                    maxValInRow = root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        
        return max;
    }
};
