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
    
    int length(ListNode *head){
        int length = 0;
        
        for(ListNode *temp = head; temp ;temp = temp->next)
            length++;
        
        return length;
    }
    
    ListNode* nextnNode(ListNode *head, int n){
        
        ListNode *node = head;
        
        while(n--)
            node = node -> next;
        
        return node;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lengthA = length(headA);
        int lengthB = length(headB);
        ListNode *tempA = headA, *tempB = headB;
        
        if(lengthA > lengthB)
            tempA = nextnNode(tempA, lengthA - lengthB);
        else
            tempB = nextnNode(tempB, lengthB - lengthA);
        
        
        while(tempA && tempB){
            
            if(tempA == tempB)
                return tempA;
            
            tempA = tempA->next;
            tempB = tempB->next;
        
        }
        
        return NULL;
    }
};
