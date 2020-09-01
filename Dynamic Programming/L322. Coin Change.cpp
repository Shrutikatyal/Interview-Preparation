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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,amount + 1);
        dp[0] = 0;
        
        for(int i=1; i <= amount; i++)
            for(int j=0; j < coins.size(); j++)
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
