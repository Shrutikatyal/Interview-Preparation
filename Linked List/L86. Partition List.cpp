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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* beforeDummy = new ListNode(0);
        ListNode* afterDummy = new ListNode(0);
        
        ListNode* before = beforeDummy;
        ListNode* after = afterDummy;
        
        while(head) {
         
            if(head->val < x){
                
                before->next = head;
                before = before->next;
            }
            else{
                
                after->next = head;
                after = after->next;
            }
            
            head = head->next;
        }
        
        after->next = NULL;
        before->next = afterDummy->next;
        
        return beforeDummy->next;
    }
};
