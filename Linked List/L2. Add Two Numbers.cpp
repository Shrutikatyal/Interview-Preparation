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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode(0);
        ListNode* parent = l3;
        int carry = 0;
        
        while(l1 || l2 || carry){
            
            ListNode* temp = new ListNode(0);
            temp->val = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = temp->val/10;
            temp->val %= 10;
                        
            parent->next = temp;
            parent = temp;
            
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        
        return l3->next;
        
    }
};
