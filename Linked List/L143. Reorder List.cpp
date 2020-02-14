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
    
    ListNode* findMiddleElt(ListNode *head){
        ListNode *slowPtr = head, *fastPtr = head;
        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        return slowPtr;
    }
    
    void reorderList(ListNode* head) {
        ListNode *root = head;
        ListNode *middlePtr = findMiddleElt(head);
        ListNode *temp = reverse(middlePtr);
        
        while(head && temp){
            ListNode* next = head->next;
            head->next = temp;
            temp = temp->next;
            head->next->next = next;
            head = next;
        }
        
        if(head && !temp)
            head->next = NULL;
        
        head = root;
    }
};


