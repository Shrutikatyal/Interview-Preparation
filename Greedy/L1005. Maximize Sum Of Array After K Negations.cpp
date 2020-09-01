/*
 * Author : Shruti Katyal
 * Date   : 01 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int sum = 0;
        
        //Flip all negatives
        for(int i=0; K > 0 && i < A.size() && A[i]<0; i++, K--)
            A[i] = -A[i];
        
        //If k is odd then just flip the minimum
        return accumulate(A.begin(),A.end(),0) - (K%2) * *min_element(A.begin(), A.end()) * 2;
        
    }
};
