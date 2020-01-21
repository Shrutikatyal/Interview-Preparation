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
    int rangeBitwiseAnd(int m, int n) {
        while(n>m)
            n = n & n-1;
        return n;
    }
};
