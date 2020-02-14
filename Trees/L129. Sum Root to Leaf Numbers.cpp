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
    unsigned int sum;
public:
    void sumNumbers(TreeNode* node,unsigned int pathSum) {
        if(node==NULL) return;
        
        if(node && !node->left && !node->right){
            sum += (10*pathSum + node->val);
            return;
        }
        
        sumNumbers(node->left, pathSum*10 + node->val);
        sumNumbers(node->right, pathSum*10 + node->val);
            
    }
    
    unsigned int sumNumbers(TreeNode* root){
        sum = 0;
        sumNumbers(root,0);
        return sum;
    }
};
