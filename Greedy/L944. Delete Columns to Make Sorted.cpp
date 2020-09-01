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
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        
        for(int i=0; i < A[0].size(); i++)
            for(int j=0; j < A.size()-1; j++)
                if(A[j][i] > A[j+1][i]){
                    ans++;
                    break;
                }
        
        return ans;
        
    }
};
