/*
 * Author : Shruti Katyal
 * Date   : 29 January, 2020
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        queue<TreeNode*> que;
        
        if(root==NULL) return avg;
        
        que.push(root);
        while(!que.empty()) {
            long long int sum=0;
            int count = 0;
            int size = que.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
           
           double avrg = (double) sum/size; 
           avg.push_back(avrg);
        }
        
        return avg;
    }
};
