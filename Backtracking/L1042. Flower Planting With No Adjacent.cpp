/*
 * Author : Shruti Katyal
 * Date   : 16 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
    vector<int> gardens;
    int totalGarden;
public:
    bool isSafeToPlacePlant(int plantNo,int gardenNo,vector<vector<int>> &adj){
        
        for(int v : adj[gardenNo])
            if(gardens[v]==plantNo)
                return false;
        return true;
    }
    
    bool selectPlantInGarden(vector<vector<int>> &adj, int gardenNo){
        
        if(gardenNo >= totalGarden)
            return true;
        
        //Try placing each plant in the garden
        for(int i=1;i<=4;i++)
            if(isSafeToPlacePlant(i,gardenNo,adj)){
                gardens[gardenNo] = i;
                if(selectPlantInGarden(adj,gardenNo + 1))
                    return true;
                gardens[gardenNo] = 0;
            }
        
        return false;
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        gardens = vector<int>(N,0);
        totalGarden = N;
        vector<vector<int>> adj(N);
        
        for(auto path:paths){
            adj[path[0]-1].push_back(path[1]-1);
            adj[path[1]-1].push_back(path[0]-1);
        }
        
        selectPlantInGarden(adj,0);
        
        return gardens;
    }
};
