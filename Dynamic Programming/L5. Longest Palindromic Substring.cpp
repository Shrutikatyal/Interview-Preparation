/*
 * Author : Shruti Katyal
 * Date   : 26 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        
        for(int i=0; i < s.length(); i++){
            
            //For odd length Palindrome
            int len1 = expandAroundCenter(s,i,i);
            
            //For even length Palindrome            
            int len2 = expandAroundCenter(s,i,i+1);
            
            int len = max(len1,len2);
            
            
            if(end - start + 1 < len){
                //Change start and end
                start = i - (len-1)/2;
                end = i + len/2;
            }
            
        }
        
         return s.substr(start,end-start+1);
    }
    
    int expandAroundCenter(string s, int l, int r){
        
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        
        return r-l-1;
    }
    
};
