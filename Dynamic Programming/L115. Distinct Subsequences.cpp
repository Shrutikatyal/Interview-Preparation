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
    int numDistinct(string s, string t) {
        vector<vector<long long int>> dp(2, vector<long long int>(t.length()+1,0));
        
        dp[0][0] = dp[1][0] = 1;
        
        for(int i=1; i<=s.length(); i++)
            for(int j=1; j<=t.length(); j++)
                if(s[i-1] != t[j-1])
                    dp[i%2][j] = dp[(i-1)%2][j];
                else
                    dp[i%2][j] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j];
        
        return dp[s.length()%2][t.length()];
        
    }
};
