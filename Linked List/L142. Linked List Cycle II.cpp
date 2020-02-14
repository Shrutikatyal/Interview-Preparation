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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        bool cycle = false;
        
        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr==fastPtr){
                cycle = true;
                break;
            }
        }
        
        if(cycle){
            
            slowPtr = head;
            while(slowPtr!=fastPtr)
            {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return slowPtr;
        }
        
        return NULL;
    }
};
