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
    int min;
	long long int secondMin;
public:
    void findSecondMin(TreeNode* node){
        if(!node) return;
        
       if(min < node->val && node->val < secondMin)
           secondMin = node->val;
       else if(node->val == min){
           findSecondMin(node->left);
           findSecondMin(node->right);
       }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        secondMin = LONG_MAX;        
        min = root->val;
        findSecondMin(root);
        return secondMin < LONG_MAX?secondMin:-1;
    }
};
