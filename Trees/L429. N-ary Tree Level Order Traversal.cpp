/*
 * Author : Shruti Katyal
 * Date   : 05 February, 2020
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> trav;
        
        vector<int> level;
        
        if(root){
            q.push(root);
            q.push(NULL);
        }
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(temp==NULL) {
                trav.push_back(level);
                level.clear();
                if(q.size())
                    q.push(NULL);
            }
            else {
                
                level.push_back(temp->val);
                for(Node* child : temp->children)
                    if(child)
                        q.push(child);
                
            }  
        }
        
        return trav;
    }
};
