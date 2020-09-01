/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int numUniqueEmails2(vector<string>& emails) {
        
        unordered_set<string> ids;
        
        for(string s:emails){
            string res = "";
            int flag = 0;
            
            for(char ch: s)
                if(ch == '@'){
                    flag = 2;
                    res += ch;
                }
                else if(ch=='+' && flag!=2)
                    flag = 1;
                else if(flag == 1)
                    continue;
                else if(ch == '.' && flag!=2)
                    continue;
                else 
                    res += ch;
                    
            
            ids.insert(res);
        }
        
        return ids.size();
    }
    
    
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> ids;
        
        for(string s:emails){
            int i = -1;
            
            for(int j=0; j < s.length(); j++)
                switch(s[j]){
                    case '@': 
                              while(j < s.length())
                                s[++i] = s[j++];
                              break;
                        
                    case '.': break;
                    
                    case '+': 
                              while(j < s.length())
                                  if(s[j] == '@'){
                                      j--; 
                                      break;
                                  }
                                  else
                                      j++;
                              break;
                    default : s[++i] = s[j];    
                                
                }
                    
            s.resize(i+1);
            ids.insert(s);
        }
        
        return ids.size();
    }
    
};
