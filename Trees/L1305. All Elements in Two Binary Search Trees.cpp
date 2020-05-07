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
    
    void populateLeft(stack<TreeNode*> &s, TreeNode* node){
        
        while(node){
            s.push(node);
            node = node->left;
        }
        
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res;
        stack<TreeNode*> s1, s2;
        
        //Get smallest element for both trees
        populateLeft(s1,root1);
        populateLeft(s2,root2);
        
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty()? s2 : s2.empty()? s1: s1.top()->val < s2.top()->val ? s1 : s2;
            
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            populateLeft(s, node->right);
            
        }
        
        return res;
    }
};
