/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 // { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);


/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;

        cin>>n1>>n2;
        int d1 , d2 , temp;
        cin>>d1;
        head1 = new Node(d1);
        tail1 = head1;
        for(i=1; i<n1; i++)
        {
            cin>>temp;
            tail1->next = new Node(temp);
            tail1 = tail1->next;
        }
        cin>>d2;
        head2 = new Node(d2);
        tail2 = head2;
        for(i=1; i<n2; i++)
        {
            cin>>temp;
            tail2->next = new Node(temp);
            tail2 = tail2->next;
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}



// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    if(head1 == NULL)
        return head1;
    
    if(head2 == NULL)
        return head2;
    
    Node *dummy = new Node(1);
    Node *prev = dummy;
    
    while(head1 && head2){
        if(head1->data < head2->data){
            prev->next = head1;
            head1 = head1->next;
        }
        else{
            prev->next = head2;
            head2 = head2->next;
            
        }
        prev = prev->next;    
    }
    
    if(head1)
        prev->next = head1;
    
    if(head2)
        prev->next = head2;
        
    return dummy->next;
}

