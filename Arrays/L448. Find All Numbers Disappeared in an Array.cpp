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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]) - 1;    
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        
        for(int i=0;i<nums.size();i++)
            if(nums[i] > 0)
                res.push_back(i+1);
        
        return res;
    }
};
