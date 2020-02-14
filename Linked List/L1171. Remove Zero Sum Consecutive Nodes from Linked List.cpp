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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> accSum;
        ListNode *root = new ListNode(0);
        root->next = head;
        
        accSum[0] = root;
        int ac = 0;
        
        while(head){
            
            ac += head->val;
            if(accSum.find(ac)!=accSum.end()){
                ListNode *start = accSum[ac];
                ListNode *temp = start->next;
                
                int aux = ac;
                while(temp!=head){
                    aux += temp->val;
                    accSum.erase(aux);
                    temp = temp->next;
                }
                
                start->next = head->next;
            }
            else
                accSum[ac] = head;
            
            head = head->next;
        }
        
        return root->next;
    }
};
