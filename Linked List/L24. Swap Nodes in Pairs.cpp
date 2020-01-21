/*
 * Author : Shruti Katyal
 * Date   : 21 January, 2020
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* temp = head;
        
        while(temp && temp->next)
        {
            temp->val = temp->val ^ temp->next->val;
            temp->next->val = temp->val ^ temp->next->val;
            temp->val = temp->val ^ temp->next->val;
        
            temp = temp->next->next;
        }
            
        return head;
    }
};
