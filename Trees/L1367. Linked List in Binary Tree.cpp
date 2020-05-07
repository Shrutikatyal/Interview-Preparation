/*
 * Author : Shruti Katyal
 * Date   : 6 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool findSubPath(ListNode* head, TreeNode* root){
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        
        return head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
        
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL)
            return false;
        return findSubPath(head, root) || isSubPath(head,root->left) || isSubPath(head,root->right);    
    }
};
