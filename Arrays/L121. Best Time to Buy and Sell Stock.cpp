/*
 * Author : Shruti Katyal
 * Date   : 13 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPrice = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(minPrice>prices[i])
                minPrice = prices[i];
            else if(maxPrice < prices[i]-minPrice)
                maxPrice = prices[i]-minPrice;
        }
        return maxPrice;
    }
};
