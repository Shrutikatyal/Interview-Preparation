/*
 * Author : Shruti Katyal
 * Date   : 14 April, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int scoreOfParentheses(string S) {
        int bal = 0, ans = 0;
        
        for(int i=0;i<S.size();i++){
            
            if(S[i]=='(')
                bal++;
            if(S[i]==')'){
                bal--;
                if(S[i-1] == '(')
                    ans += 1<<bal;
            }
        }
        
        return ans;
    }
};


