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
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int count = 0;
        int maxLen = 0;
        for(int i=0; i<nums.size()-1;i++){
            count = nums[i] < nums[i+1]? count+1:0;
            maxLen = max(maxLen, count);
        }
        
        return maxLen + 1;
    }
};
