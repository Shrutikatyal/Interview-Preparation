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
    int getLength(ListNode *head) {
        int count = 0;
        for(ListNode *temp = head; temp; temp = temp->next)
            count++;
        
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or k==0) return head;
        
        k = k % getLength(head);
        ListNode *first = head, *second = head;
        
        for(; k>0; k--)
            first = first->next;
        
        while(first->next) {
            first = first->next;
            second = second->next;
        }
        
        first->next = head;
        head = second->next;
        second->next = NULL;
        
        return head;
    }
};
