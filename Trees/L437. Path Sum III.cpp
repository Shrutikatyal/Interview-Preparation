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
    int hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        return (root->val == sum ? 1 : 0) + hasPathSum(root->left,sum - root->val) + hasPathSum(root->right,sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum){
        if(!root)
            return 0;
        return hasPathSum(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
            
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
    unordered_map<int,int> preSum;
    unsigned int count;
public:
    void helper(TreeNode* root, int currSum, int target){
        if(root==NULL) return;
        
        currSum += root->val;
        if(preSum.find(currSum - target)!=preSum.end())
            count += preSum[currSum - target];
        
        if(preSum.find(currSum)==preSum.end())
            preSum[currSum] = 1;
        else
            preSum[currSum] += 1;
        
        helper(root->left,currSum,target);
        helper(root->right,currSum,target);
        //So that same solution does not added up more than once
        preSum[currSum] -= 1;
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        preSum[0] = 1;
        count = 0;
        helper(root,0,sum);
        return count;
    }
};
