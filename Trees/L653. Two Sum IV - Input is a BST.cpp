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
    vector<int> trav;
public:
    void inOrder(TreeNode *node) {
        if(node){
            inOrder(node->left);
            trav.push_back(node->val);
            inOrder(node->right);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int left = 0, right = trav.size()-1;
        while(left < right){
            int sum = trav[left] + trav[right];
            if(sum == k)
                return true;
            if(sum < k)
                left = left + 1;
            else
                right = right - 1;
        }
        return false;
    }
};
