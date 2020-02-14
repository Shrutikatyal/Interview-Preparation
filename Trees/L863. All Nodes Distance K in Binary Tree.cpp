/*
 * Author : Shruti Katyal
 * Date   : 07 February, 2020
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
    TreeNode* target;
    int K;
    vector<int> nodes;
   
    //dist it has already travelled
    void subtree_add(TreeNode* node,int dist) {
        if(node==NULL) return;
        if(dist == K)
            nodes.push_back(node->val);
        else {
            subtree_add(node->left,dist+1);
            subtree_add(node->right,dist+1);
        }
        
    }
    
    int dfs(TreeNode* root) {
        if(root==NULL)
            return -1;
        if(root==target){
            subtree_add(root,0);
            return 1;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left!=-1){
            if(left==K) {
                nodes.push_back(root->val);
            }
            else
                subtree_add(root->right,left+1);
            return left+1;
        }
        
        if(right!=-1){
            if(right==K){
                nodes.push_back(root->val);
            }
            else
                subtree_add(root->left,right+1);
            return right+1;
        }
        
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->target = target;
        this->K = K;
        dfs(root);
        return nodes;
    }
};
