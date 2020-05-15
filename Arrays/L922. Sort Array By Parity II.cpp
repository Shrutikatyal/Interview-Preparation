/*
 * Author : Shruti Katyal
 * Date   : 15 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
       int even = 0, odd = 1; 
       vector<int> B(A.size());
       for(int i=0;i<A.size();i++)
           if(A[i]%2){
               B[odd] = A[i];
               odd += 2;
           }
           else{
               B[even] = A[i];
               even += 2;
           }
        
    return B;
    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1;
        for(int even = 0; even < A.size(); even += 2){
            if(A[even]%2 == 1){
                while(A[odd]%2 == 1)
                    odd += 2;
            swap(A[odd],A[even]);
            }
        }
        
        return A;
    }
};
