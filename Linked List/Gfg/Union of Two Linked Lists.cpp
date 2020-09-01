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

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	new node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node* makeUnion(struct node* head1, struct node* head2);

int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(makeUnion(a, b));
    }
    return 0;
}
// } Driver Code Ends


/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    map<int,int> count;
    node *dummy = new node(1); 
    int ans = 0;
    
    node *parent = dummy;
    
    if(head1==NULL || head2==NULL)
        return dummy->next;
    
    while(head1)
        count[head1->data]++, head1 = head1->next;
        
    while(head2)
        count[head2->data]++, head2 = head2->next;
        
    for(auto elt : count)
        if(elt.second){
            parent->next = new node(elt.first);
            parent = parent->next;
        }
            
        
    return dummy->next;
    
}

