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
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(),1), count(nums.size(),1);
        
        for(int i=1; i<nums.size(); i++)
            for(int j=0; j< i; j++)
                if(nums[i] > nums[j]){
                    
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[i]==dp[j]+1)
                        count[i] += count[j];
                    
                }
        
        int maxLen = 0, ans = 0;
        
        for(int i=0; i<nums.size();i++)
            if(dp[i] > maxLen)
                maxLen = dp[i], ans = count[i];
            else if(dp[i]==maxLen)
                ans += count[i];
        
        return ans;
    }
};
