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
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        
        for(int i=1; i<=num;i++)
            res[i] = res[i & (i-1)] + 1;
        
        return res;
    }
};
