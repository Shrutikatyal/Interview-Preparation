/*
 * Author : Shruti Katyal
 * Date   : 04 February, 2020
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
class BSTIterator {
    stack<TreeNode*> s;
    
    void inorder_left(TreeNode*  root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        inorder_left(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* next = s.top();
        s.pop();
        if(next->right)
            inorder_left(next->right);
        return next->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
