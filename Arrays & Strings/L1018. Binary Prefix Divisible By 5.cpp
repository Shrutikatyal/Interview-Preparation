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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        
        vector<bool> divisible(A.size());
        int num = 0;
        
        for(int i=0; i < A.size(); i++){
            num = (num * 2 + A[i]) % 5;
            divisible[i] = !num; 
        }
            
        return divisible;
    }
};
