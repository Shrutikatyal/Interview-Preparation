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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stack;
        for(ListNode* temp = head; temp; temp = temp->next)
            res.push_back(temp->val);
        for(int i=res.size()-1;i>=0;i--)
        {
            int val = res[i];
            while(!stack.empty() && stack.back()<= val) stack.pop_back();
            res[i] = stack.empty()?0:stack.back();
            stack.push_back(val);
        }
        
        return res;
    }
};
