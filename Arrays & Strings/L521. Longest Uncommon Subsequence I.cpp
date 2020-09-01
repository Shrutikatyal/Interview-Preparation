/*
 * Author : Shruti Katyal
 * Date   : 19 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int findLUSlength(string a, string b) {
        
        return a==b? -1 : max(a.size(),b.size());
    }
};
