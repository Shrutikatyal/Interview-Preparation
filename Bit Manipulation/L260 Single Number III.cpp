/*
 * Author : Shruti Katyal
 * Date   : 21 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xorNum = 0;
        
        for(int i:nums)
            xorNum ^= i;
        
        vector<int> res = {0,0};
        int rightMostSetBit = xorNum & -xorNum;
        
        for(int i:nums)
            if(rightMostSetBit & i)
                res[0] = res[0] ^ i;
            else
                res[1] = res[1] ^ i;
        
        return res;
        
    }
};
