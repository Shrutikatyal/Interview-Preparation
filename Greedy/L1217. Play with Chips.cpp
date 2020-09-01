/*
 * Author : Shruti Katyal
 * Date   : 02 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        
        int oddCount = 0, evenCount = 0;
        
        //Odd position can shift to odd position with 0 cost. Same goes for even.
        
        for(int pos : chips)
            if(pos & 1) oddCount++; else evenCount++;
        
        return min(oddCount,evenCount);
    }
};
