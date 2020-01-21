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
    ListNode* removeElements(ListNode* head, int val) {
    
        ListNode* parent = new ListNode(0);
        parent->next = head;
        ListNode* root = parent;
        
        while(head)
        {
            if(head->val == val){
                parent->next = head->next;
                //free(head);
                head = parent->next;
            }
            else{
                parent = head;
                head = head->next;
            }        
        }
        
        return root->next;
    }
};

