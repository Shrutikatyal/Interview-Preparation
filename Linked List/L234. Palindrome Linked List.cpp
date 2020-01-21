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
    bool isPalindrome(ListNode* head) {
        
        ListNode* slowPtr = head, *fastPtr = head, *prev = NULL;
        
        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            //Reversing first half
            ListNode* next = slowPtr->next;
            slowPtr->next = prev;
            prev = slowPtr;
            slowPtr = next;
        }
        
        //If length of linked list is odd
        if(fastPtr)
            slowPtr = slowPtr->next;
        
        while(slowPtr)
        {
            if(prev->val != slowPtr->val)
                return 0;
            prev = prev->next;
            slowPtr = slowPtr->next;
        }
        
        return 1;
        
    }
};


