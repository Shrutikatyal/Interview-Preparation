/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */


class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^= n >> 2) & n-1);
    }
};


