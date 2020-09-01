/*
 * Author : Shruti Katyal
 * Date   : 13 June, 2020
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
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        if(visited.find(node) != visited.end())
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto n: node->neighbors)
            cloned->neighbors.push_back(cloneGraph(n));
        
        return cloned;    
    }
};
