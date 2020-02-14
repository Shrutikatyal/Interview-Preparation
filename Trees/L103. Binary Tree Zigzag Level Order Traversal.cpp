/*
 * Author : Shruti Katyal
 * Date   : 31 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> trav;
        queue<TreeNode*> que;
        int i=0;
        
        if(root) 
            que.push(root);
        while(!que.empty()){
            trav.push_back({});    
            queue<TreeNode*> temp;
            
            while(!que.empty()){
                TreeNode* node = que.front();
                que.pop();
                if(i%2)
                    trav[i].insert(trav[i].begin(),node->val);
                else 
                    trav[i].push_back(node->val);
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
            que = temp; 
            i++;
        }
        
        return trav;
    }
};


//ANOTHER APPROACH
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
public:
    void reverse(vector<int> &v){
        for(int i=0,j=v.size()-1;i<j;i++,j--){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
            
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> trav;
        queue<TreeNode*> que;
        int i=0;
        
        if(root) 
            que.push(root);
        while(!que.empty()){
            trav.push_back({});    
            queue<TreeNode*> temp;
            
            while(!que.empty()){
                TreeNode* node = que.front();
                que.pop();
                trav[i].push_back(node->val);
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
            if(i%2)
                reverse(trav[i]);
            que = temp; 
            i++;
        }
        
        return trav;
    }
};
