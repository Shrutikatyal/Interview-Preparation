/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int strStr2(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        for(int i=0;i<haystack.size()-needle.size()+1;i++)
        {
            int j;
            for(j=0;j<needle.size();j++)
                if(haystack[i+j]!=needle[j])
                    break;
            if(j==needle.size())
                return i;
        }
        return -1;
    }
    
    
    vector<int> computeLPS(string s){
        
        vector<int> lps(s.size(), 0);
        
        int i = 1, j = 0;
        
        while( i < s.length() ){
            
            if(s[i]==s[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else if(j==0)
                lps[i++] = 0;
            else
                j = lps[j-1];
        }
        
        return lps;
    }
    
     int strStr(string haystack, string needle) {
         
         if(haystack.size() < needle.size())
             return -1;
         
         if(needle.size() == 0)
             return 0;
         
         vector<int> lps = computeLPS(needle);
         
         int i=0, j=0;
         
         while(i < haystack.size()){
             if(haystack[i] == needle[j]){
                 i++;
                 j++;
                 if(j == needle.size())
                     return i-j;
             }
             else if(j==0)
                 i++;
             else
                 j = lps[j-1];
         }
         
         return -1;
     }
    
};
