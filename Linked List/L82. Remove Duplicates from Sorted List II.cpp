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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        bool flag;
        
        while(head && head->next){
            
            while(head->next && head->val == head->next->val)
            {
                flag = 1;
                head->next = head->next->next;
            }
            
            if(flag) {
                prev->next = head->next; 
                flag=0;
            }
            else
                prev = head;
            
            head = head->next;
        }
        
        return dummy->next;
        
    }
};
