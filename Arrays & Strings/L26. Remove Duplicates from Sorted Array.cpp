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
    int removeDuplicates2(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]==nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        return nums.size()-count;
    }
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int count = 0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]!=nums[count])
               nums[++count] = nums[i];
        return count + 1;
    }
};
