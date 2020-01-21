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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *root,*temp;
        ListNode *parent=new ListNode(0);
        root = parent;
        
        while(l1!=NULL or l2!=NULL)
        {
            if(l1==NULL)
            {
                temp = new ListNode(l2->val);
                parent->next = temp;
                l2 = l2->next;
            }
            
            else if(l2==NULL)
            {
                temp = new ListNode(l1->val);
                parent->next = temp;
                l1 = l1->next;
            }
            
            else if(l1->val<l2->val)
            {
                temp = new ListNode(l1->val);
                parent->next = temp;
                l1 = l1->next;
            }
            else
            {
                temp = new ListNode(l2->val);
                parent->next = temp;
                l2 = l2->next;   
            }
            
            parent = temp;
                
        }
        
        return root->next;
    }
};
