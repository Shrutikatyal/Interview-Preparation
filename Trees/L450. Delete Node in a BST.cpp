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
    vector<TreeNode*> searchNode(TreeNode* root,int key, TreeNode *parent) {
        TreeNode* temp = root;
        
        while(temp) {
            if(temp->val==key)
                return {temp,parent};
            parent = temp;
            cout<<parent->val;
            if(key < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return {};
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        
        TreeNode* parent = dummy;
        vector<TreeNode*> nodeNPar = searchNode(root,key,parent);
        
        
        if(nodeNPar.size()) {
            parent = nodeNPar[1];
            TreeNode* nodeWithKey = nodeNPar[0];
            
            if(nodeWithKey->left && nodeWithKey->right){
                
                TreeNode* temp = nodeWithKey->left;
                TreeNode* parent = nodeWithKey;
                while(temp->right) {
                    parent = temp;
                    temp = temp->right;
                }
                nodeWithKey->val = temp->val;
                
                nodeWithKey->left = deleteNode(nodeWithKey->left,temp->val);
                //delete temp;
            }
            else if(nodeWithKey->left) {
                if(parent->left == nodeWithKey)
                    parent->left = nodeWithKey->left;
                else
                    parent->right = nodeWithKey->left;
                //delete nodeWithKey;
            }
            else if(nodeWithKey->right) {
                if(parent->left == nodeWithKey)
                    parent->left = nodeWithKey->right;
                else
                    parent->right = nodeWithKey->right;
            }
            else {
                if(parent->left == nodeWithKey)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
                
        }
        
        return dummy->left;
    }
};
