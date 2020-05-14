/*
 * Author : Shruti Katyal
 * Date   : 14 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int fib(int N) {
        if(N < 2) return N;
        int a = 0;
        int b = 1, c;
        for(int i = 2; i <= N; i++){
            c = a + b;
            a = b;
            b = c;
        }
       
        return c;
    }
};
