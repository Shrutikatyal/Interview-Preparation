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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int i=0; i < nums.size(); i++){
            count = nums[i]==1? count+1 : 0;
            maxCount = max(count, maxCount);    
        }
        
        return maxCount;
    }
};
