/*
 * Author : Shruti Katyal
 * Date   : 28 January, 2020
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
    bool isSame(TreeNode *s, TreeNode *t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        
        return (s->val == t->val) && isSame(s->left,t->left) && isSame(s->right,t->right);
    }
    
    bool traverse(TreeNode* s, TreeNode *t){
        return (s && (isSame(s,t) || traverse(s->left,t) || traverse(s->right,t)));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
    }
};
