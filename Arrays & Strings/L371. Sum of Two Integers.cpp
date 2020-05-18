/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int getSum(int a, int b) {
        
        while(b)
        {
            int carry = (a & b);
            a = a ^ b;
            b = (carry & 0xffffffff)<<1; //Which bit is turned one because of carry
        }
     
        return a;
    }
};
  
