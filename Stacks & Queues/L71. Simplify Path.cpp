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
    string simplifyPath(string path) {
        stack<string> stk;
        string str = "";
        
        path += "/";
        for(int i=0;i<path.size();i++){
            
            if(path[i]=='/') {
                if(str == ".."){
                    if(!stk.empty())
                        stk.pop();
                }
                else if(str.size() && str!="." )
                    stk.push(str);
                str = "";
            }
            else
                str += path[i];
        }
        
        str = "";
        while(!stk.empty()) {
            
            str ="/"+ stk.top() + str;
            stk.pop();
        }
        
        if(str.size()==0 && path.size())
            return "/";
        return str;
    }
};
