/*
 * Author : Shruti Katyal
 * Date   : 07 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //How far can we reach from the current position? Then try from each of those positions to reach as far as possible.
        
        int i = 0, n = nums.size();
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == n;
    }
};
