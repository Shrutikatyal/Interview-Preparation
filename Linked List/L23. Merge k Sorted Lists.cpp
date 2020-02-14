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
class myComparator 
{ 
public: 
    bool operator() (const ListNode* p1, const ListNode* p2) 
    { 
        return p1->val > p2->val; 
    } 
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        priority_queue<ListNode*,vector<ListNode*>, myComparator> queue;
        
        for(ListNode* list:lists)
            if(list)
                queue.push(list);
        
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        
        while(!queue.empty()){
            dummy->next = queue.top();
            queue.pop();
            dummy = dummy->next;
            if(dummy->next)
                queue.push(dummy->next);
        }
        dummy->next = NULL;
        
        return head->next;
    }
};

//DIVIDE N CONQUER
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
