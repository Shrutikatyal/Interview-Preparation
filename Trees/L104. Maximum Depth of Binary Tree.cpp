/*
 * Author : Shruti Katyal
 * Date   : 27 January, 2020
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
    int max(int a,int b) {
        return a>b?a:b;
    }
    
    //Two things are maintained in a state the current node, the height via return value
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
