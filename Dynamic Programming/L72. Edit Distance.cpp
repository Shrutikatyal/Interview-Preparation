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
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[2][n+1];
        
        for(int i=0; i <= m; i++)
            for(int j=0; j <= n; j++)
                if(i==0)
                    dp[i%2][j] = j;
                else if(j==0)
                    dp[i%2][j] = i;
                else if(word1[i-1]!=word2[j-1])
                    dp[i%2][j] = 1 + min(dp[i%2][j-1],min(dp[(i-1)%2][j],dp[(i-1)%2][j-1]));
                else
                    dp[i%2][j] = dp[(i-1)%2][j-1];
        
        return dp[m%2][n];
        
    }
};
