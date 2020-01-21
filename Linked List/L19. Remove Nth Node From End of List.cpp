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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy, *second = dummy;
        
        for(int i=0;i<=n && first;i++)
            first = first->next;
        
        while(first){
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        return dummy->next;
    }
};
