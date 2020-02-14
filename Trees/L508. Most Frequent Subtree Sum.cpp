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
    unordered_map<int,int> count;
    
    int findTreeSum(TreeNode* root,int &maxCount) {
        if(root==NULL) return 0;
        
        int sum = root->val;
        sum += findTreeSum(root->left, maxCount);
        sum += findTreeSum(root->right, maxCount);
        count[sum]++;
        if(maxCount < count[sum])
            maxCount = count[sum];
        return sum;
    } 
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxCount = -1;
        findTreeSum(root,maxCount);
        vector<int> mostFreqSums;
        
        for(const auto& x: count)
            if(x.second == maxCount)
                mostFreqSums.push_back(x.first);
        
        return mostFreqSums;
    }
};
