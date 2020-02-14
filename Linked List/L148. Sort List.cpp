/*
 * Author : Shruti Katyal
 * Date   : 24 January, 2020
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
    ListNode* findMiddleElt(ListNode *head){
        ListNode *slowPtr = head, *fastPtr = head, *prev=NULL;
        while(fastPtr && fastPtr->next){
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        prev->next = NULL;
        return slowPtr;
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2){
        
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;
        
        while(l1 && l2){
            l3->next = l1->val < l2->val? l1: l2;
            
            if(l1->val < l2->val)
                l1 = l1->next;
            else
                l2 = l2->next;
            
            l3 = l3->next;
        }
        
        while(l1){
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
        }
        
        while(l2){
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
    
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *mid = findMiddleElt(head);
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        return merge(l1,l2);
    }
};
