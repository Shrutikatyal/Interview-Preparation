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
    vector<vector<int>> paths;
public:
    void pathSum(TreeNode* node, int sum, vector<int> path) {
        if(node==NULL) return;
        path.push_back(node->val);
        
        if(!node->left && !node->right && node->val == sum){ 
            paths.push_back(path);
        }
        
        pathSum(node->left, sum - node->val,path);
        pathSum(node->right, sum - node->val,path);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
       
        pathSum(root,sum,{});
        return paths;
    }
};
