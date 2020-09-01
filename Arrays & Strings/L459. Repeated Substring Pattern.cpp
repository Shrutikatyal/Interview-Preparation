/*
 * Author : Shruti Katyal
 * Date   : 02 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        /*https://leetcode.com/problems/repeated-substring-pattern/discuss/94360/My-one-line-c%2B%2B-solution*/
        return (str + str).find(str, 1) < str.size();
    }
};
