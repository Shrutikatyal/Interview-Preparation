/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    string sortString(string s) {
        int count[26]={0};
        string res = "";
        
        for(char ch:s)
            count[ch-'a']++;
        
        while(res.size()!=s.size()){
            
            for(int i=0; i < 26; i++)
                res += string((count[i]-- >0 ?1: 0), i + 'a');
            
            for(int i=25; i >= 0; i--)
                res += string((count[i]-- >0 ?1: 0), i + 'a');
            
        }
        
        return res;
    }
};
