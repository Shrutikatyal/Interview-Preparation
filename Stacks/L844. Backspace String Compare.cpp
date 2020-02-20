/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
    string computeString(string s){
        int stackPtr = -1;
        int i=0, len=s.size();
        
        while(i < len) {
            if(s[i]!='#')
                s[++stackPtr] = s[i++];
            while(i<len && s[i]=='#'){
                if(stackPtr>=0)
                    stackPtr--;
                i++;
            }
        }
        return s.substr(0,++stackPtr);
        
    }
public:
    bool backspaceCompare(string S, string T) {
        return computeString(S)==computeString(T);
    }
};
