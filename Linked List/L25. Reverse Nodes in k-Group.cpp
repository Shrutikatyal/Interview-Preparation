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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int count = 0;
        ListNode *curr = head;
        while(count < k){
            if(!curr) return head;
            curr = curr->next;
            count++;
        }
        
        ListNode* prev = reverseKGroup(curr,k);
        while (count > 0) {  
            ListNode *next = head->next; 
            head->next = prev; 
            prev = head; 
            head = next;
            count = count - 1;
        }
        
        return prev;
    
    }
};


/***ITERATIVE****/
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
    ListNode* reverse(ListNode* start, ListNode *end) {
        
        ListNode* prev = NULL, *curr=start;
        while(end != curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy = new ListNode(0);
        ListNode *interHead = dummy;
        ListNode *start = head;
        
        int count = 0;
        while(head){
            
            if(count && count % k == 0){
                interHead->next = reverse(start,head);    
                interHead = start;
                start = head;
            }
            
            head = head->next;
            count++;
       }
       
       if(count%k==0)
           interHead->next = reverse(start,head);
       else
           interHead->next = start;
        
       return dummy->next;
    }
};
