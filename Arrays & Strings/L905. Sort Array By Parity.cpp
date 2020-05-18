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
    vector<int> sortArrayByParity(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while(low < high){
            if(A[low]%2 && A[high]%2==0)
                swap(A[low],A[high]);
            
            if(A[low]%2 == 0) low++;
            if(A[high]%2) high--;
        }
        
        return A;
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};
