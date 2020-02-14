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
    vector<int> trav;
public:
    void postOrder(Node* node) {
        if(node) {
            for(Node* child: node->children)
                postOrder(child);
            trav.push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        postOrder(root);
        return trav;
    }
};
