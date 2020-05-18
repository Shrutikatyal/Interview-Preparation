/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        int n = A.size();
        
        for(;i<n-1 && A[i]<A[i+1];i++);
        
        //All increasing or no increasing at all
        if(i==0 || i==n-1)
            return false;
        
        for(;i<n-1 && A[i]>A[i+1];i++);
        
        //Reached end or not
        return i==n-1;
    }
};
