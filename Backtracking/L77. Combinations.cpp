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
    vector<vector<int>> combine(int n, int k) {
        if(n>=k)
        DFS(1, n, k,{});
        return res;
    }
    
    void DFS(int start, int n, int k, vector<int> nums){
        
        if(nums.size() == k)
            res.push_back(nums);
        else{
            
            for(int i=start; i<=n;i++){
                nums.push_back(i);
                DFS(i+1,n,k,nums);
                nums.pop_back();
            }
            
        }
        
    }
    
};
