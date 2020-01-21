/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Reverse 32-bits 
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t rev = n;
        
        rev = (rev << 16) | (rev >> 16);   
        rev = ( (rev & 0x00ff00ff) << 8 ) | ( (rev & 0xff00ff00) >> 8);
        rev = ( (rev & 0x0f0f0f0f) << 4 ) | ( (rev & 0xf0f0f0f0) >> 4);
        rev = ( (rev & 0x33333333) << 2 ) | ( (rev & 0xcccccccc) >> 2);
        rev = ( (rev & 0x55555555) << 1 ) | ( (rev & 0xaaaaaaaa) >> 1);
        
        return rev;
        
    }
};
