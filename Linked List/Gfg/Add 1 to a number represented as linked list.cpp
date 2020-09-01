/*
 * Author : Shruti Katyal
 * Date   : 19 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
Node* addOne(Node *head);
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
Node *ZZZZZZZZZZ(Node *head)
{
    Node * prev   = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void print(struct Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
// This function mainly uses addOneUtil().
int main() {
	// your code goes here
	int T;
	cin>>T;
	int no;
	while(T--)
	{
		struct Node *head = NULL;
        struct Node *temp = head;
        
		cin>>no;
		while(no!=0)
			{
			if(head==NULL)
			head=temp=newNode(no%10);
			else
			{
				temp->next = newNode(no%10);
				temp=temp->next;
			}
			no/=10;
		}
		head = ZZZZZZZZZZ(head);
		
		head=addOne(head);
		print(head);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/* Node structure
struct Node
{
    int data;
    Node* next;
}; */

Node* reverse(Node *head){
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// Returns new head of linked List.
Node *addOne(Node *head)
{
   // Your Code here
   
   Node* node = reverse(head);
   head = node;
   
   
   int carry = 1;
   
   while(carry && node){
        int sum = node->data + carry;
        node->data = sum%10;
        carry = sum/10;
        node = node->next;
   }
   
   head = reverse(head);
   
   if(carry){
       node = new Node();
       node->data = carry;
       node->next = head;
       head = node;
   }
    
   return head;
}
