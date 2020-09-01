/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0],nums[1]);
        
        int value1 = nums[0], value2 = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            int value3 = max(value1+nums[i], value2);
            value1 = value2;
            value2 = value3;
        }
        
        return value2;
    }
};
