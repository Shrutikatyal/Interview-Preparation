/*
 * Author : Shruti Katyal
 * Date   : 05 February, 2020
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
class Codec {
    
    void encode(TreeNode* root, string &order) {
        if(root==NULL) return;
        
        char buff[4];
        memcpy(&buff,&(root->val),sizeof(root->val));
        
        for(int i=0;i<4;i++) order.push_back(buff[i]);
        encode(root->left,order);
        encode(root->right,order);
        
    }
    
    TreeNode* reconstruct(string data, int &pos, int min, int max){
        if(pos >= data.size())
            return NULL;
        int value;
        memcpy(&value, &data[pos], sizeof(value));
        
        if(value > max || value < min) return NULL;
        
        pos += sizeof(int); 
        TreeNode* node = new TreeNode(value);
        node->left = reconstruct(data,pos,min,value);
        node->right = reconstruct(data,pos,value,max);
        return node;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        encode(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        return reconstruct(data,pos,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
