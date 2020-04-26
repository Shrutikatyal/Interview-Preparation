/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    string removeDuplicates(string S) {
        int stkPtr = -1;
        int length = S.size();
        
        for(int i=0;i<length;)
            if(stkPtr==-1 || S[i]!=S[stkPtr])
                S[++stkPtr] = S[i++];
            else
                while(stkPtr!=-1 && i<length && S[stkPtr]==S[i]){
                    stkPtr--;
                    i++;
                }
        
        S[++stkPtr]='\0';
        return S;
    
    }
};
