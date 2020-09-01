/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 // { Driver Code Starts
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *sortedInsert(struct Node *head, int data);

Node *last = nullptr;

void append(struct Node **headRef, int newData) {
    struct Node *new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
        last = *headRef;
        return;
    }
    //    while (last->next != NULL)last = last->next;
    last->next = new_node;
    last = last->next;
}
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

/* Drier program to test count function*/
int main() {
    int test;
    cin >> test;
    while (test--) {
        struct Node *head = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            append(&head, k);
        }
        cin >> k;
        head = sortedInsert(head, k);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should return head of the modified linked list
Node *sortedInsert(struct Node* head, int data) {
    // Code here
    Node *dummy = new Node(1);
    dummy->next = head;
    
    Node *prev = dummy;
    
    while(head && head->data < data)
        prev=head, head = head->next;
    
    prev->next = new Node(data);
    prev->next->next = head;
    
    return dummy->next;
    
}

