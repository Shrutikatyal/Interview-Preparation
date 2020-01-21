/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Majority Element
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0];
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(count==0)
                candidate = nums[i];
        
            count += (nums[i]==candidate)? 1: -1;
        }
        
        return candidate;
    }
};
