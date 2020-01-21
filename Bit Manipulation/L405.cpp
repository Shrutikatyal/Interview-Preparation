/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Dec To Hexa
 */
 
class Solution {
public:
    string toHex(int num) {
        
        if(num==0) return "0";
        
        string hex = "0123456789abcdef";
        string res;
        int count = 0;
        
        while(num && count++ < 8)
        {
            res = hex[num & 0xf] + res;
            num = num >> 4;
        }    
        
        return res;
        
    }
};
