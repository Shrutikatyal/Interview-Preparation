/*
 * Author : Shruti Katyal
 * Date   : 31 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int numTrees(int n) {
        if(n<1) return 0;
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i] += dp[j] * dp[i-j-1];
        
        return dp[n];
    }
};
