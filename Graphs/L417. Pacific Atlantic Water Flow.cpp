/*
 * Author : Shruti Katyal
 * Date   : 13 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
    int m,n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<vector<int>>();
        }
        
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n,0));
        vector<vector<bool>> atlantic(m, vector<bool>(n,0));
        
        for(int i=0; i < m; i++){
            
            if(!pacific[i][0])
                flowPacific(i,0,matrix,pacific);
            
            if(!atlantic[i][n-1])
                flowAtlantic(i,n-1,matrix,atlantic);
            
        }
        
        
        for(int j=0; j <n; j++){
            
            if(!pacific[0][j])
                flowPacific(0,j,matrix,pacific);
            
            if(!atlantic[m-1][j])
                flowAtlantic(m-1,j,matrix,atlantic);
            
        }
        
        vector<vector<int>> res;
        
        for(int i=0; i < m; i++)
            for(int j=0; j<n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
        
        return res;
    }

    
    void flowOcean(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>> &ocean){
        
        ocean[i][j] = true;
        
        //If this is true then only it can flow to the ocean
        if(i-1 >= 0 && !ocean[i-1][j] && matrix[i-1][j] >= matrix[i][j])
            flowOcean(i-1,j,matrix,ocean);
        
        if(i+1 < m && !ocean[i+1][j] && matrix[i+1][j] >= matrix[i][j])
            flowOcean(i+1,j,matrix,ocean);
            
        if(j-1 >= 0 && !ocean[i][j-1] && matrix[i][j-1] >= matrix[i][j])
            flowOcean(i,j-1,matrix,ocean);
            
        if(j+1 < n && !ocean[i][j+1] && matrix[i][j+1] >= matrix[i][j])
            flowOcean(i,j+1,matrix,ocean);
        
    }
    
     void flowPacific(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>> &pacific){
        flowOcean(i,j,matrix,pacific);
     }
    
    void flowAtlantic(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>> &atlantic){
        flowOcean(i,j,matrix,atlantic);
    }
};
