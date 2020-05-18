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
        if(prices.size()==0)
            return 0;
//         int i = 0;
//         int maxProfit = 0;
//         int peak=prices[0];
//         int valley= prices[0];
        
//         while(i<prices.size()-1)
//         {
//             while(i<prices.size()-1 and prices[i]>=prices[i+1])
//                 i++;
//             valley = prices[i];
//             while(i<prices.size()-1 and prices[i]<=prices[i+1])
//                 i++;
//             peak = prices[i];
//             maxProfit += peak-valley;
                
//         }
        
//         return maxProfit;
        
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
            if(prices[i]>prices[i-1])
                maxProfit+=prices[i]-prices[i-1];
        return maxProfit;
    }
};



