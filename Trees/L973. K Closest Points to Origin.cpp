/*
 * Author : Shruti Katyal
 * Date   : 10 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 */

class Solution {
    struct myComparator{
      bool operator()(vector<int> a, vector<int> b){
          return  a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];  
      }  
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,myComparator> q;
        vector<vector<int>> res;
        
        for(int i=0; i<points.size(); i++){
            q.push(points[i]);
            if(q.size() > K)
                q.pop();
        }
        
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        
        return res; 
    }
};
