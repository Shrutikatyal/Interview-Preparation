/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include <map>
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mapping ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i = s.length()-1;
        int num = 0;
        while(i>=0)
        {
            if(i<s.length()-1 and mapping[s[i]] < mapping[s[i+1]]) 
                num -= mapping[s[i]];
            else
                num += mapping[s[i]];
            i -= 1;
        }
        return num;
    }
};
