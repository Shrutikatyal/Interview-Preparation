/*
 * Author : Shruti Katyal
 * Date   : 26 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        DFS(nums,0,res);
        return res;
    }
    
    void DFS(vector<int> nums, int pos, vector<vector<int>> &res){
        if(pos == nums.size())
            res.push_back(nums);
        else 
            for(int i=0; i<=pos; i++){
                swap(nums[i], nums[pos]);
                DFS(nums,pos+1,res);
                swap(nums[i], nums[pos]);
            }
    }
};
