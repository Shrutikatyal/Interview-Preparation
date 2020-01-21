/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Difference between two strings 
 */
 
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char res=0;
        
        for(char ch:s) res^=ch;
        for(char ch:t) res^=ch;
        
        return res;
    }
};
