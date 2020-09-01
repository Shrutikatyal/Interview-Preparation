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
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++)
            for(int j=0;j<i;j++)
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        
        int length = 0;
        for(int x:dp)
            length = max(length,x);
        
        return length;
    }
};
