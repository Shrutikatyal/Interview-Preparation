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
    bool isCousins(TreeNode* root, int x, int y, bool siblings = false, bool cousin = false) {  
      queue<TreeNode*> queue, temp;
      queue.push(root);  
      while(!queue.empty() && !cousin) {
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            if(node == NULL) siblings = false;
            else {
                if(node->val==x || node->val==y)
                    if(!cousin)
                      siblings = cousin = true;
                    else
                      return !siblings;
                temp.push(node->left);
                temp.push(node->right);
                temp.push(NULL);
            }
        }  
        swap(queue,temp);
      }  
      
      return false;
    }
};
