/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    ListNode* head;
public:
    
    int getLength(ListNode* head){
        int count=0;
        for(ListNode* temp = head; temp; temp = temp->next, count++);
        return count;
    }
    
    TreeNode* convertListToBST(int l, int r){
        
        if(l > r)
            return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode* left = convertListToBST(l,mid-1);
        
        TreeNode* node = new TreeNode(head->val);
        node->left = left;
        
        head = head->next;
        
        node->right = convertListToBST(mid+1,r);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        int len = getLength(head);
        
        return convertListToBST(0,len-1);
    }
};
