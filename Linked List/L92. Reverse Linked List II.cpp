/*
 * Author : Shruti Katyal
 * Date   : 22 January, 2020
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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        int i=0;
        
        for(i=0;i<m-1;i++)
            before = before->next; 
        
        ListNode* prev = before->next;
        ListNode* curr = prev->next;
        
        for(;i<n-1;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
            
        before->next->next = curr;
        before->next = prev;
        
        return dummy->next;
    }
};

