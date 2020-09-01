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
    bool canPartition(vector<int>& nums) {
    
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum % 2)
            return false;
        
        sum = sum/2;
        
        vector<bool> dp(sum + 1,0);
        dp[0] = true;
        
         for(int i=0; i < nums.size(); i++)
             for(int j=sum - nums[i]; j >= 0; j--)
                 if(dp[j])
                     dp[j + nums[i]] = 1; 
                     
                     OR
        
        for(int i=0; i < nums.size(); i++)
            for(int j=sum; j >= nums[i]; j--)
                if(dp[j-nums[i]])
                    dp[j] = 1; 
        
        return dp[sum];
    }
};
