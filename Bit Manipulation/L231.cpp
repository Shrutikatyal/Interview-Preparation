/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Power of 2
 */


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & n-1);
    }
};
