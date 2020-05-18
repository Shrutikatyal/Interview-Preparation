/*
 * Author : Shruti Katyal
 * Date   : 12 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0 && carry;i--){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if(carry)
            digits.insert(digits.begin(),carry);
        
        return digits;
    }
};
