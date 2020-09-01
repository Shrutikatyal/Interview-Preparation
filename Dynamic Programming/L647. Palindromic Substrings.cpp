/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
    int ans;
public:
    int countSubstrings(string s) {
        ans = 0;
        
        for(int i=0; i < s.length(); i++){
            
            //For odd length Palindrome
            expandAroundCenter(s,i,i);
            
            //For even length Palindrome            
            expandAroundCenter(s,i,i+1);
            
        }
        
        return ans;
    }
    
    int expandAroundCenter(string s, int l, int r){
        
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            ans++;
            r++;
        }
        
        return r-l-1;
    }
};
