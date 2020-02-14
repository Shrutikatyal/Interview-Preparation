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
    
    ListNode* reverse(ListNode* head){  
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *sum = new ListNode(0);
        ListNode *l3 = sum;
        
        int carry = 0;
        
        while(l1 || l2 || carry){
            
            ListNode* node = new ListNode(0);
            node->val = (l1?l1->val:0)+(l2?l2->val:0)+(carry?carry:0);
            carry = node->val/10;
            node->val %= 10;
            
			l3->next = node;
			l3 = l3->next;
			
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        return reverse(sum->next);
    }
};
