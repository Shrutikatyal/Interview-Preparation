/*
 * Author : Shruti Katyal
 * Date   : 11 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        
        //buy = hold and sell = cash 
        const int buy = 0, sell = 1;
        
        int dp[n][2];
        
        dp[0][buy] = - prices[0];
        dp[0][sell] = 0;
        
        for(int i=1; i<n; i++){
            
            //Try to sell
            dp[i][sell] = max(dp[i-1][sell], dp[i-1][buy] + prices[i]);
            
            //Try to hold/buy
            dp[i][buy] = -prices[i];
            
            //Deduct it from the current profit or cash in hand
            //i-2 because of cooldown
            if(i >=2 ) dp[i][buy] += dp[i-2][sell];
            
            //Whether to buy or not?
            dp[i][buy] = max(dp[i-1][buy], dp[i][buy]);
            
        }
        
        return dp[n-1][sell];
        
    }
};
