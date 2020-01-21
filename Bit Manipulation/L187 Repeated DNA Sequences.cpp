/*
 * Author : Shruti Katyal
 * Date   : 21 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<int,int> substrings;
        vector<string> result;
       
        int i=0,size=s.size();
        long long t=0;
        
        while(i<9)
            t = t << 3 | s[i++] & 7;
        
        while(i<size)
            if(substrings[t = t << 3 & 0x3FFFFFFF | s[i++] & 7 ]++ == 1)
                result.push_back(s.substr(i-10,10));
        
        return result;
        
    }
};

