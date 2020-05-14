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
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==val)
                count++;
            else
                nums[i-count] = nums[i];
        return nums.size()-count;
    }
};
