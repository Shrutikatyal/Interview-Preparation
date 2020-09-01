/*
 * Author : Shruti Katyal
 * Date   : 21 May, 2020
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



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

int length(Node *head){
    int len = 0;
    
    while(head)
        head = head->next, len++;
        
    return len;
}

// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int k)
{
    // Your Code here
    int n = length(head);
    
    if(n < k || 2*k - 1 == n) return head;
    
    Node *dummy = new Node(1);
    dummy->next = head;
    
    Node *x_prev = dummy;
    Node *y_prev = dummy;
    Node *x = head, *y = head;
    
    for(int i = 1; i < k; i++){
        x_prev = x;
        x = x->next;
    }
    
    for(int i = 1; i < n-k+1; i++){
        y_prev = y;
        y = y->next;
    }
    
    x_prev->next = y;
    y_prev->next = x;
    
    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    return dummy->next;
}

