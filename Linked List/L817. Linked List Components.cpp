/*
 * Author : Shruti Katyal
 * Date   : 26 January, 2020
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> subset;
        int count = 0;
        ListNode* curr = head;
        
        for(int i:G) subset.insert(i);
        
        while(curr){
            if(subset.find(curr->val)!=subset.end() && (!curr->next || subset.find(curr->next->val)==subset.end()))
                count++;
            curr = curr->next;
        }
     
        return count;
    }
};
