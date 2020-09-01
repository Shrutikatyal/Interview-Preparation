/*
 * Author : Shruti Katyal
 * Date   : 21 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */

void rearrange(struct Node *odd);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        rearrange(start);
        printList(start);
    }
    return 0;
}
// } Driver Code Ends


/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/

void rearrange(struct Node *odd)
{
    //add code here
    Node *evenDummy = new Node(1);
    
    Node *p1 = NULL;
    Node *p2 = evenDummy;
    bool even = true;
    
    while(odd){
        if(even){
            p2->next = odd;
            odd = odd->next;
            p2 = p2->next;
        }
        else {
            if(p1==NULL){
                p1 = odd;
                odd = odd->next;
                p1->next = NULL;
            }
            else
            {
                Node *temp = p1;
                p1 = odd;
                odd = odd->next;
                p1->next = temp;
            }
        }
        
        even = !even;
    }
    
    p2->next = p1;
    odd = evenDummy->next;
}


