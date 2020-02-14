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
    int minDiff;
    TreeNode* prev;
public:
    void getMinDiff(TreeNode* node){
        if(node==NULL)
            return;
        getMinDiff(node->left);
        
        if(prev) {
            int diff = abs(prev->val - node->val);
            minDiff = (diff < minDiff)? diff : minDiff;
        }
        
        prev = node;
        getMinDiff(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        getMinDiff(root);
        return minDiff;
    }
};


