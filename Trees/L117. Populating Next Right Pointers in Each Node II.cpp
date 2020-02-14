/*
 * Author : Shruti Katyal
 * Date   : 04 February, 2020
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        Node* head = NULL;
        Node* prev = NULL;
        
        while(curr){
            
            //For each level mark next
            while(curr){
                //Left child
                if(curr->left){
                    if(prev)
                        prev->next = curr->left;
                    else
                        head = curr->left;
                    prev = curr->left;
                }
                
                //Right child
                if(curr->right){
                    if(prev)
                        prev->next = curr->right;
                    else
                        head = curr->right;
                    prev = curr->right;
                }
                
                curr = curr->next;
            }
            
            //For next level
            curr = head;
            head = NULL;
            prev = NULL;
        }
        
        return root;
    }
};
