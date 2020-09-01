/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

struct myCompare{
    
    bool operator()(vector<int> i, vector<int> j){
        if(i[0] != j[0])
            return i[0] < j[0];
        return i[1] < j[1];
    }
};

class Solution {
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>,vector<vector<int>>, myCompare> pq;
        vector<int> res;
        
        for(int i=0; i < mat.size(); i++){
            
            pq.push({numOfOnes(mat[i]),i});
            
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty()){
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    int numOfOnes(vector<int> row){
        
        int low = 0, high = row.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(row[mid]==1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};
