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
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int localMax = nums[0], localMin = nums[0], globalMax = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0)
                swap(localMin, localMax);
            
            localMax = max(localMax*nums[i],nums[i]);
            localMin = min(localMin*nums[i],nums[i]);
            globalMax = max(localMax,globalMax);
        }
        
        return globalMax;
            
    }
};
