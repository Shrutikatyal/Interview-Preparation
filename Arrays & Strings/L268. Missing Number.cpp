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
    int missingNumber(vector<int>& nums) {
        
        int missingNum = nums.size();
        
        for(int i=0;i<nums.size();i++)
            missingNum ^= i ^ nums[i];  
        
        return missingNum;
    }
};
