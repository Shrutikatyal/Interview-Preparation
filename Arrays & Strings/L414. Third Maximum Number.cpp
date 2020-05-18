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
    int thirdMax(vector<int>& nums) {
        long max = LONG_MIN;
        long secMax = LONG_MIN;
        long thirdMax = LONG_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                thirdMax = secMax; 
                secMax = max;
                max = nums[i];
            }
            else if(nums[i] > secMax && nums[i]!=max){
                thirdMax = secMax;
                secMax = nums[i];
            }
            else if(nums[i] > thirdMax && nums[i]!=secMax && nums[i]!=max)
                thirdMax = nums[i];    
        }
            
        return thirdMax == LONG_MIN ? max : thirdMax;
    }
};
