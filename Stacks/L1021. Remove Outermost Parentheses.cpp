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
    string removeOuterParentheses(string S) {
        string primitive = "";
        int count = 0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(') {
                count++;
                if(count>1)
                    primitive += S[i];
            }
            else {
                count--;
                if(count!=0)
                    primitive += S[i];
            }
        }
        
        return primitive;
    }
};
