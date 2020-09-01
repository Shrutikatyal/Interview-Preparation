/*
 * Author : Shruti Katyal
 * Date   : 10 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        //Maintain two sliding windows
        int n = text.size();
        unordered_set<string> substrings;
        
        for(int len=1; len <= n/2 ; len++){
            
            int same = 0;
            //Initialize the window
            for(int i=0; i < len; i++)
                if(text[i]==text[i+len]) same++;
            
            
            //Shift windows
            for(int j=0; j <= n-len*2; j++){
                
                //Check for last window
                if(same == len) substrings.insert(text.substr(j,len));
                
                if(j==n-len*2) break;
                
                //Remove first elt from last window
                if(text[j] == text[j+len]) same--;
                
                //Add len+j to first window and len*2 + j to second
                if(text[len+j] == text[j + len*2]) same++;
                
            }
                
            
        }
            
        return substrings.size();
        
    }
};

