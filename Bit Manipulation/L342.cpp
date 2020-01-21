/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Power of 4
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && !(n & n-1) && !(n & 0xAAAAAAAA);
    }
};

