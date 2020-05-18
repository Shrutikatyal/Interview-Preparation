/*
 * Author : Shruti Katyal
 * Date   : 15 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        
        for(int i=0; i < nums.size(); i++)
            if(leftSum == sum - leftSum - nums[i])
                return i;
            else
                leftSum += nums[i];
        
        return -1;
    }
};
