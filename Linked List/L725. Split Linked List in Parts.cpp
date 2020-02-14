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
    short length(ListNode *root) {
        short len = 0;
        for(ListNode* temp=root;temp;temp=temp->next)
            len++;
        
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, short k) {
        vector<ListNode *> heads(k);
        short len = length(root);
        short sizeOfParts = len/k;
        short remaining = len%k;

        for(short i = 0; i < k; i++) {
            ListNode *lastNode = NULL;
            for(short j=0; j < (sizeOfParts + ((i<remaining)?1:0)); j++){
                if(!heads[i])
                    heads[i] = root;
                lastNode = root;
                root = root->next;
            }
                   
            if(lastNode)
                lastNode->next = NULL;
        }
        
        return heads;
    }
};
