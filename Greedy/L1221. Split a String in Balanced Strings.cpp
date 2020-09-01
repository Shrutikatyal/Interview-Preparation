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
    int balancedStringSplit(string s) {
        int bal = 0, ans = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='R') 
                bal++;
            else
                bal--;
            ans = (bal==0)? ans + 1 : ans;        
        }    
        
        return ans;
    }
};
