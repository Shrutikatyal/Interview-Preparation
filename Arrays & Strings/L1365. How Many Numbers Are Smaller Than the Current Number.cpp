/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int map[101] = {0};
        vector<int> res(nums.size());
        
        for(int num:nums)
            map[num]++;
        
        for(int i=1; i < 101; i++)
            map[i] += map[i-1];
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                res[i] = 0;
            else 
                res[i] = map[nums[i] - 1];
        }
        
        return res;
    }
    
};
