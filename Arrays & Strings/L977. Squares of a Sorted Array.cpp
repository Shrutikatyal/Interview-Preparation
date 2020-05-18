/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    int findTransitionPoint(vector<int> &A){
        int low = 0, high = A.size() - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(A[mid]>=0 && (mid==low || A[mid-1]<0))
                return mid;
            else if(A[mid] < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return A.size();
    }
    
    vector<int> sortedSquares(vector<int>& A) {
        int transitionPt = findTransitionPoint(A);
        int i = transitionPt - 1;
        int j = transitionPt;
        vector<int> res;
        
        while(i >= 0 && j < A.size()){
            if(abs(A[i]) < A[j])
                res.push_back(A[i]*A[i--]);
            else
                res.push_back(A[j]*A[j++]);
                
        }
        
        while(i >= 0)
            res.push_back(A[i]*A[i--]);
        
        while(j < A.size())
            res.push_back(A[j]*A[j++]);
        
        return res;
    }
};
