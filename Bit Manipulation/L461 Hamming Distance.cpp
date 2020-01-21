/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Hamming distance
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        return bitset<32>(x^y).count();
        
    }
};
