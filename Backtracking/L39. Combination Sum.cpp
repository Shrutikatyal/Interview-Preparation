/*
 * Author : Shruti Katyal
 * Date   : 26 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        DFS(candidates,0,target,{});
        return res;
    }
    
    void DFS(vector<int> nums,int start, int target,vector<int> comb){
        
        if(target==0)
            res.push_back(comb);
        else{
            
            for(int i=start; i < nums.size() && target >= nums[i]; i++){
                comb.push_back(nums[i]);
                DFS(nums,i,target-nums[i],comb);
                comb.pop_back();
            }
            
        }
        
    }
};
