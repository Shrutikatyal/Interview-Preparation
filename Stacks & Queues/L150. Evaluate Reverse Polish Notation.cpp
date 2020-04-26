/*
 * Author : Shruti Katyal
 * Date   : 17 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(string str: tokens){
            if(str=="+"){
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                stack.push_back(a+b);
            }
            else if(str=="-"){
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                stack.push_back(a-b);
            }
            else if(str=="/"){
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                stack.push_back(a/b);
            }
            else if(str=="*"){
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                stack.push_back(a*b);
            }
            else
                stack.push_back(stoi(str));
        }
        
        return stack[0];
    }
};
