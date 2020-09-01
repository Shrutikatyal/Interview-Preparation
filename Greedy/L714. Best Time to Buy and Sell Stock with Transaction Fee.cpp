/*
 * Author : Shruti Katyal
 * Date   : 03 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        int cash = 0, hold = -price[0];
        for(int i=1;i<price.size();i++){
            cash = max(cash,hold+price[i]-fee);
            hold = max(hold, cash-price[i]);
        }
        
        return cash;
    }
};
