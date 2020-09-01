/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<0  || n<0) return 0;
        
        vector<int> dp(n,1);
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[j] += dp[j-1];
        
        return dp[n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<0  || n<0) return 0;
        
        vector<vector<int>> dp(2, vector<int>(n,0));
        
        for(int i=0; i<m; i++)
            dp[i%2][0] = 1;
        
        for(int j=0; j<n; j++)
            dp[0][j] = 1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
        
        return dp[(m-1)%2][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<0  || n<0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++)
            dp[i][0] = 1;
        
        for(int j=0; j<n; j++)
            dp[0][j] = 1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};
