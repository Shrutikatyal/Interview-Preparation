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
    bool isSubsequence(string s, string t) {
        
        int j = 0;
        
        for(int i=0; i <t.size() && j < s.size(); i++)
            if(s[j] == t[i])
                j++;
        
        return j==s.size();
    }
};
