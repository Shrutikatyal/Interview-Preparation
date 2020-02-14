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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* sortedPtr = dummy;
        ListNode* curr = head;
        
        while(curr){
            ListNode* next = curr->next;
            
            while(sortedPtr && sortedPtr->next && sortedPtr->next->val < curr->val)
                sortedPtr = sortedPtr->next;
            
           
            curr->next = sortedPtr->next;
            sortedPtr->next = curr;
            
            curr = next;
            sortedPtr = dummy;
        }
        
        return dummy->next;
    }
};


