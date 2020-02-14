/*
 * Author : Shruti Katyal
 * Date   : 04 February, 2020
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
    //Post-order traversal
    int countNodes(TreeNode* node) {
        if(node == NULL)
            return 0;
                
        return countNodes(node->left) + countNodes(node->right) + 1;
    }
};

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
    int height(TreeNode* root) {
        return root == NULL ? -1 : 1 + height(root->left);
    }
    
    int countNodes(TreeNode* root) {
        int h = height(root);
        return h < 0 ? 0 :
               height(root->right) == h-1 ? (1 << h) + countNodes(root->right)
                                         : (1 << h-1) + countNodes(root->left);
    }
    
};
