/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Hamming weight 
 */


class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        for(;n;count++,n=n&n-1);
        return count;
    }
};
