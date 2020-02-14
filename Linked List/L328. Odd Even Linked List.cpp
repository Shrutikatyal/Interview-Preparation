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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* oddDummy = new ListNode(0);
        ListNode* evnDummy = new ListNode(0);
        ListNode* oddPtr = oddDummy;
        ListNode* evnPtr = evnDummy; 
        
        int count = 1;
        while(head){
            if(count%2){
                oddPtr->next = head;
                oddPtr = oddPtr->next;
            }
            else{
                evnPtr->next = head;
                evnPtr = evnPtr->next;
            }
            count++;
            head = head->next;
        }
        
        oddPtr->next = evnDummy->next;
        evnPtr->next = NULL;
        
        return oddDummy->next;
    }
};
