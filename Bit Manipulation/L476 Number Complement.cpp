/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Complement of a number
 */
 
class Solution {
public:
    int findComplement(int num) {
        
        unsigned mask = ~0;
        
        while(num & mask)  mask <<= 1;
        
        return ~mask & ~num;
    }
};

