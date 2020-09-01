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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<int> degree(n);
        vector<vector<int>> e(n);
        for(auto edge:edges){
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        vector<int> q;
        
        for(int i=0; i<n; i++)
            if(degree[i]==1)    //If it is a leaf
                q.push_back(i);
        
        while(n>2){
            int size = q.size();
            for(int i=0; i < size; i++){
                int u = q.front();
                q.erase(q.begin());
                n--;
                
                for(auto v: e[u])
                    if(--degree[v]==1)
                        q.push_back(v);
            }
        }
        
        return q;
    }
};
