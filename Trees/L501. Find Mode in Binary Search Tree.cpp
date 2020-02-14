/*
 * Author : Shruti Katyal
 * Date   : 28 January, 2020
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
    int currCount, maxCount;
    TreeNode* prev;
public:
    void inOrder(TreeNode* node, vector<int> &modes) {
        if(node==NULL) 
            return;
        
        inOrder(node->left,modes);
            
        if(prev)
            currCount = (prev->val == node->val)? currCount+1 : 1;
        else
            currCount = 1;
        prev = node;
        
        if(currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(node->val);
        }
        else if(currCount == maxCount)
            modes.push_back(node->val);
        
        inOrder(node->right,modes);    
    }
    
    vector<int> findMode(TreeNode* root) {
        currCount = maxCount = 0;
        vector<int> modes;
        inOrder(root, modes);
        return modes;
    }
};
