/*
 * Author : Shruti Katyal
 * Date   : 18 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> digits;
        for(int i=0;i<num.size(); i++) {
            while(!digits.empty() && k>0 && digits.top()>(num[i])){
                digits.pop();
                k--;
            }
            
            if(!(digits.empty() && num[i]=='0'))
                digits.push(num[i]);
        }
        
        while(k && !digits.empty()){
            digits.pop();
            k--;
        }
        
        string n;
        while(!digits.empty()) {
            n = digits.top() + n ;
            digits.pop();
        }
        
        
        if(n.size()==0)
            return "0";
        return n;
    }
};

