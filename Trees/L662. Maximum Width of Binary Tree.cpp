/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
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
    ulong ans;
    unordered_map<int,int> map;
public:
    void dfs(TreeNode *node, int depth, ulong pos){
        if(node==NULL) return;
        if(map.find(depth)==map.end())
            map[depth] = pos;
        ans = max(ans,pos-map[depth]+1);
        dfs(node->left,depth+1,pos*2);
        dfs(node->right,depth+1,pos*2+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root,0,0);
        return ans;
    }
};
