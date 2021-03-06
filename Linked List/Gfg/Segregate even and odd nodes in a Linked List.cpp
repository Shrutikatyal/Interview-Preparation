/*
 * Author : Shruti Katyal
 * Date   : 19 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void segregateEvenOdd(Node **head);

void insert(Node **head)
{
    int n,i,value;
    Node *temp;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        
        if(i==0)
        {
            *head = new Node(value);
            temp = *head;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
        }
    }
}

void printList(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,n,value;
    
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     
     Node* head = NULL;
     
     while(t--)
     {
         head = NULL;
        insert(&head);
        segregateEvenOdd(&head);
        printList(head);
     }
     return(0);
}
// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element  
  node is defined as 

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
}*head;
*/

void segregateEvenOdd(struct Node** head)
{
   // The task is to complete this method
   
   if(*head==NULL)
    return;
   
   Node *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;

   Node *curr = *head;
   
   while(curr!=NULL)
   {
       int value = curr->data;
       
       if(value%2==0)
       {
           if(evenStart == NULL)
           {
               evenStart = curr;
               evenEnd = curr;
           }
           else
           {
                evenEnd->next = curr;
                evenEnd = curr;
           }
       }
       else
       {
           if(oddStart == NULL)
           {
               oddStart = curr;
               oddEnd = curr;
           }
           else
           {
                oddEnd->next = curr;
                oddEnd = curr;
           }
       }
     
        curr = curr->next;
   }
   
   if(evenStart==NULL || oddStart==NULL)
        return;
    
   evenEnd->next = oddStart;
   oddEnd->next = NULL;
   *head = evenStart;
    
}
