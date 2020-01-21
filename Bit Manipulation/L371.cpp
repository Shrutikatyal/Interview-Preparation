/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Sum without using +, -
 */
class Solution {
public:
    int getSum(int a, int b) {
        
        while(b)
        {
            int carry = (a & b);
            a = a ^ b;
            b = (carry & 0xffffffff)<<1;
        }
     
        return a;
    }
};
