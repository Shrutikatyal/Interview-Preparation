/*
 * Author : Shruti Katyal
 * Date   : 10 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int distinctSubseqII(string S) {
        int mod = pow(10, 9) + 7, n = S.length();
        int dp[n + 1];        
        dp[0] = 1;
        
        vector<int> last(26, -1);
        
        for (int i = 1; i <= n; i++) {
            int x = S[i-1] - 'a';
            dp[i] = 2 * dp[i-1] % mod;

            if (last[x] >= 0) 
                dp[i] -= dp[last[x]];
            
            dp[i] %= mod;
            last[x] = i-1;
        }  
            
        dp[n]--;
        if(dp[n]<0) dp[n] += mod;
        
        return dp[n];
    }
};
