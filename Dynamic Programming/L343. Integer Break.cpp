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
    int integerBreak(int n) {
        
        vector<int> dp(n+1);
        
        dp[0] = 0, dp[1] = 1;
        
        for(int i=2; i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i] = max(dp[i],max((i-j)*j, (i-j)*dp[j]));
        
        return dp[n];
        
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if(n==2 || n==3) return n-1;
        
        int res = 1;
        while(n>4){
            res = res * 3;
            n -= 3;
        }
        
        return res*n;
    }
};
