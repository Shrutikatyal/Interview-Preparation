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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        
        TreeNode *node = root;
        
        while(node) {
            int parentVal = node->val;
            
            if(pVal > parentVal && qVal > parentVal)
                node = node->right;
            else if(pVal < parentVal && qVal < parentVal)
                node = node->left;
            else
                return node;
        }
        
        return NULL;
    }
};
