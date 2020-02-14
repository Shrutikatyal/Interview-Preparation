/*
 * Author : Shruti Katyal
 * Date   : 24 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
     
        for(Node* temp = head; temp; temp = temp->next){
            
            if(temp->child){
                
                Node *next = temp->next;
                Node *child = temp->child;
                temp->next = child;
                child->prev = temp;
                temp->child = NULL;
                
                while(child->next)
                    child = child->next;
                
                child->next = next;
                
                if(next)
                    next->prev = child;
            }
            
        }
        
        return head;
    }
};
