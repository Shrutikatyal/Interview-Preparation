/*
 * Author : Shruti Katyal
 * Date   : 14 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]!=0)
                nums[index++] = nums[i];
        
        while(index <  nums.size())
            nums[index++] = 0;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]!=0)
                swap(nums[index++], nums[i]);
    }
};
