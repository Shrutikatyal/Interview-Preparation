/*
 * Author : Shruti Katyal
 * Date   : 04 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool isMatch(string str, string pattern) {
        int match = 0, s = 0, p = 0, starIdx = -1;
        
        while(s < str.length()){
            
			// advancing both pointers
            if(p < pattern.length() && (pattern[p]=='?' || pattern[p]==str[s]))
                s++,p++;
                
            //Advancing only pattern pointer
            else if(p < pattern.length() && pattern[p]=='*'){
                starIdx = p;
                p++;
                match = s;
            }
            
            //Advacing only string pointer when matching a char with prev pointer which was *
            else if(starIdx != -1){
                p = starIdx + 1;
                match++;
                s = match;
            }
            
			//current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            else return false;
        }
        
       while(p < pattern.length() && pattern[p]=='*')
           p++;
        
       return p==pattern.length();
    }
};
