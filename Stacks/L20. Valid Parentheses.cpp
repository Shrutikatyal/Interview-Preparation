/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[': st.push(s[i]);
                          break;
                case ')': if(st.empty() || st.top()!='(') return false;
                          st.pop();
                          break;
                case '}': if(st.empty() || st.top()!='{') return false;
                          st.pop();
                          break;
                case ']': if(st.empty() || st.top()!='[') return false;
                          st.pop();
                          break;
            }
        }
        
        return st.empty();
    }
};
