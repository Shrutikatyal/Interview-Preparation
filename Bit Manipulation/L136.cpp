/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : SIngle occuring element
 */
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++)
            res = res ^ nums[i];
        return res;
    }
};


