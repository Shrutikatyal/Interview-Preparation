/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
    
    int rob(vector<int> &nums, int start, int end){
        int prev = 0, curr = 0;
        
        for(int i=start; i < end; i++){
            int maxVal = max(prev + nums[i], curr);
            prev = curr;
            curr = maxVal;
        }
            
        return curr;
    }
};
