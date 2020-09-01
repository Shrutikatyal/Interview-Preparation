/*
 * Author : Shruti Katyal
 * Date   : 27 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 
class Solution {
public:
    string minWindow(string s, string t) {
        int hashPat[256] = {0};
        int hashStr[256] = {0};
        
        if(t.length() > s.length())
            return "";
        
        for(char ch: t)
            hashPat[ch]++;
        
        int count = 0, start = 0, start_index = -1, minLen = s.length()+1;
        
        for(int i=0; i < s.length(); i++){
            
            hashStr[s[i]]++;
            
            if(hashPat[s[i]]!=0 && hashStr[s[i]] <= hashPat[s[i]])
                count++;
            
            if(count == t.length()){
                
                while(hashStr[s[start]] > hashPat[s[start]] || hashPat[s[start]]==0){
                    
                    if(hashStr[s[start]] > hashPat[s[start]])
                        hashStr[s[start]]--;
                    
                    start++;
                }
                
                int length = i - start + 1;

                if(length < minLen){
                    minLen = length;
                    start_index = start;
                }
                
            }
            
        }
        
        if(start_index == -1)
            return "";
        
        return s.substr(start_index,minLen);
        
    }
};
