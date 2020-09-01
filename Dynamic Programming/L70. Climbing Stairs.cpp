/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)
            return n;
        int value1 = 1, value2 = 2;
        
        for(int i=3;i<=n;i++){
            int value3 = value1 + value2;
            value1 = value2;
            value2 = value3;
        }
            
        return value2;
    }
};
