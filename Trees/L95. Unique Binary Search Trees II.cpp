/*
 * Author : Shruti Katyal
 * Date   : 31 January, 2020
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
    TreeNode* clone(TreeNode* node){
        if(node==NULL) return NULL;
        TreeNode* n = new TreeNode(node->val);
        n->left = clone(node->left);
        n->right = clone(node->right);
        return n;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return {};
        vector<TreeNode*> res(1,NULL);
        
        for(int i=1;i<=n;i++){
            vector<TreeNode*> temp;
            for(int j=0;j<res.size();j++){
                TreeNode* oldRoot = res[j];
                TreeNode* root = new TreeNode(i);
                TreeNode* target = clone(oldRoot);
                root->left = target;
                temp.push_back(root);
                
                if(oldRoot){
                    TreeNode* oldTemp = oldRoot;
                    while(oldTemp->right){
                        //Root ke right main new node and new node ke left main oldroot ka right 
                        TreeNode *node = new TreeNode(i);
                        node->left = oldTemp->right;
                        oldTemp->right = node;
                        TreeNode* target = clone(oldRoot);
                        temp.push_back(target);
                        //Reverse the action
                        oldTemp->right = node->left;
                        oldTemp = oldTemp->right;
                    }
                    
                    oldTemp->right = new TreeNode(i);
                    TreeNode* target = clone(oldRoot);
                    temp.push_back(target);
                    oldTemp->right = NULL;
                }
            }
            
            res = temp;
        }
        
        return res;
    }
};
