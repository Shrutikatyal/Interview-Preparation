/*
 * Author : Shruti Katyal
 * Date   : 12 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int maxSum=nums[0],curSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(curSum+nums[i]<nums[i])
                curSum = nums[i];
            else
                curSum = nums[i]+curSum;
            
            if(curSum>maxSum)
                maxSum = curSum;
        }
        
        return maxSum;
    }
};
