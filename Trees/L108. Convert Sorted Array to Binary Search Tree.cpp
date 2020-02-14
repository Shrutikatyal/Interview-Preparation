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
    TreeNode* convertToBST(int left, int right, const vector<int> nums){
        if(left > right)
            return NULL;
        int mid = (left + right)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = convertToBST(left, mid-1,nums);
        node->right = convertToBST(mid+1,right,nums);
        
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int length = nums.size();
       return convertToBST(0,length-1,nums);
    }
};
