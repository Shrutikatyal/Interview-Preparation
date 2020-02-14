/*
 * Author : Shruti Katyal
 * Date   : 26 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Node{
 public:
    int val;
    Node* next;
    Node(int v){ val = v; next=NULL;}
};

class MyLinkedList {
    Node *head;    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        Node *temp=head;
        int i=0;
        for(;i<index && temp;i++,temp=temp->next);
        
        if(i!=index || temp==NULL)
            return -1;
        return temp->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        Node *dummy = new Node(0);
        dummy->next = head;
        head = dummy;
        
        while(head->next){
            head = head->next;
        }
        
        head->next = new Node(val);
        head = dummy->next;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(index <= 0){
            addAtHead(val);
            return;
        }
        
        int parentIndex = index - 1;
        Node *temp = head;
        
        while(parentIndex-- && temp){
            temp = temp->next;
        }
        
        if(temp == NULL || parentIndex > 0)
            return;
        
        if(temp->next == NULL){
            addAtTail(val);
            return;
        }
        
        Node *node = new Node(val);
        node->next = temp->next;
        temp->next = node;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(!head || index < 0)
            return;
        
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *temp = dummy;
        
        while(temp && index-- > 0){
            temp = temp->next;    
        }
        
        if(temp && temp->next)
            temp->next = temp->next->next;
        
        head = dummy->next;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
