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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Difference between max and min would be the greatest;
    int maxAncestorDiff(TreeNode* root, int maxVal = 0, int minVal = 100000) {
        if(root == NULL)
            return maxVal - minVal;
        maxVal = max(root->val, maxVal);
        minVal = min(root->val, minVal);
        return max(maxAncestorDiff(root->left, maxVal, minVal), maxAncestorDiff(root->right, maxVal, minVal));
    }
};
