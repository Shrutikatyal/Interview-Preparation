/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        
//         if(str1.size() < str2.size()) return gcdOfStrings(str2, str1);
//         if(str2 == "") return str1;
//         if(str1.substr(0,str2.size()) != str2) return ""; 
        
//         return gcdOfStrings(str1.substr(str2.size()),str2);
        return (s1 + s2 == s2 + s1)  ? s1.substr(0, gcd(size(s1), size(s2))) : "";
    }
};
