/*
 * Author : Shruti Katyal
 * Date   : 07 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        
        //Number ways to get target = number of ways to get sum(target - (partitions));
        dp[0] = 1;
        
        for(int i=0; i<=target; i++)
            for(int j=0; j<nums.size(); j++)
                if(nums[j] <= i)
                    dp[i] += dp[i-nums[j]];
        
        return dp[target];
    }
};
