/*
 * Author : Shruti Katyal
 * Date   : 02 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()< 2)
            return nums.size();
        
        int lastDiff = 0, count = 1;
        
        for(int i=1; i < nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            if(!(diff==0 || (diff<0 && lastDiff<0) ||  (diff>0 && lastDiff>0)))
            {
                lastDiff = diff;
                count++;
            }

        }
        
        return count;
    }
};
