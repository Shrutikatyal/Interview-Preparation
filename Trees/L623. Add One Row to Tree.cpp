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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> q;
        TreeNode* temp = root;
        if(root) {
            q.push(temp);
            q.push(NULL);
        }
        if(d==1) {
            TreeNode *dupLeft = new TreeNode(v);
            dupLeft->left = root;
            root = dupLeft;
        }
        
        d--;
        
        while(!q.empty()) {
    
            temp = q.front();
            q.pop();
            if(temp==NULL) {
               d--;
               if(d==0)
                   break;
               if(q.size())
                   q.push(NULL);
            }
            else {
                if(d==1) {
                  TreeNode *dupLeft= new TreeNode(v);
                  dupLeft->left = temp->left;
                  TreeNode *dupRight= new TreeNode(v);
                  dupRight->right = temp->right;  
                
                  temp->left = dupLeft;
                  temp->right = dupRight;
                }
              else{
                  if(temp->left)
                      q.push(temp->left);
                  if(temp->right)
                      q.push(temp->right);
              }
                    
            }
        }
        
        return root;
    }
};
