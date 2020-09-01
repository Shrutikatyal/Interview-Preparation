/*
 * Author : Shruti Katyal
 * Date   : 07 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int L[2][n+1];
        
        for(int i=0; i <= m; i++)
            for(int j=0; j <= n; j++) {
                if( i==0 || j==0 )
                    L[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    L[i%2][j] = 1 + L[(i-1)%2][j-1];
                else
                    L[i%2][j] = max(L[(i-1)%2][j], L[i%2][j-1]);
            }
        
        return L[m%2][n];
    }
};
