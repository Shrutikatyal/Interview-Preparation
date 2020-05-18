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
    double findMaxAverage(vector<int>& nums, int k) {
        
        double maxSum;
        double sum = 0;
        
        for(int i=0; i < k;i++)
            sum += nums[i];
        
        maxSum = sum;
        
        for(int i=k; i <nums.size(); i++){
            sum +=nums[i] - nums[i-k];
            maxSum = max(sum, maxSum);
        }
        
        return maxSum/k;
    }
};
