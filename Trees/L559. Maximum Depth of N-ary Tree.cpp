/*
 * Author : Shruti Katyal
 * Date   : 28 January, 2020
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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        
        int maxHt = 0;
        for(Node* child : root->children)
            maxHt = max(maxDepth(child),maxHt);
        
        return maxHt + 1;
    }
};
