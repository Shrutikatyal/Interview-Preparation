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
    string decodeString(string s) {
    
        int i=0, num =0;
        string res;
        stack<int> stk;
        stack<string> chars;
        
        while(i<s.size()){
            
            if(isdigit(s[i]))
                num = num*10 + (s[i]-'0');
            else if(isalpha(s[i]))
                res += s[i];
            else if(s[i]=='['){
                chars.push(res);
                stk.push(num);
                num = 0;
                res = "";
            }
            else if(s[i]==']'){
                string tmp = res;
                for(int k=0;k<stk.top()-1;k++)
                    res += tmp;
                res = chars.top() + res;
                chars.pop(); 
                stk.pop();
            }
            i++;
        }
        
        return res;
    }
};
