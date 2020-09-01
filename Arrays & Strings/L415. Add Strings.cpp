/*
 * Author : Shruti Katyal
 * Date   : 02 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i, diff = num1.size() - num2.size();
        string res = num1.size()>num2.size()? num1:num2;
        num2 = num1.size()>num2.size()? num2:num1;
        
        for(i=num2.size()-1; i >=0 ;i--){
            int sum = res[i+abs(diff)] - '0' + num2[i] - '0' + carry;
            carry = sum/10;
            res[i+abs(diff)] = sum % 10 + '0';
        }
        
        i = abs(diff)-1;
        
        while(carry && i>=0){
            int sum = res[i]+carry-'0';
            carry = sum/10;
            res[i--] = sum%10+'0';  
        }
        
        if(carry)
            res.insert(res.begin(),carry+'0');
        
        return res;
        
    }
};

