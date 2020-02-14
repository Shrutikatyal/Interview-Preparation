/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
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
    int findMax(vector<int> nums, int start, int end) {
        int index = start;
        for(int i=start+1;i<=end;i++) 
            if(nums[index] < nums[i]) {
                index = i;
            }
        return index;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int> nums,int start, int end) {
        if(start > end)
            return NULL;
        int maxEltIndex = findMax(nums,start,end);
        TreeNode* root = new TreeNode(nums[maxEltIndex]);
        root->left = constructMaximumBinaryTree(nums,start,maxEltIndex-1);
        root->right = constructMaximumBinaryTree(nums,maxEltIndex+1,end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        return constructMaximumBinaryTree(nums,0,nums.size()-1);
    }
};
