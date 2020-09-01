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
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0, resSum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);

        vector<int> res; 
        sort(nums.begin(),nums.end());
        
        int i = nums.size() - 1;
        while(sum >= resSum){
            sum -= nums[i];
            resSum += nums[i];
            res.push_back(nums[i--]);
        }
        
        return res;
    }
};
