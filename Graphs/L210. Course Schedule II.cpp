/*
 * Author : Shruti Katyal
 * Date   : 13 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> order;
        
        for(auto x: prerequisites){
            edges[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int> q;
        
        for(int i=0; i < numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        
        int count = 0;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            order.push_back(u);
            count++;
            
            for(auto v: edges[u])
                if(--indegree[v]==0)
                    q.push(v);
            
        }
        
        return count==numCourses? order : vector<int>(0);
    }
};
