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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, sumGas = 0, sumCost = 0,start = 0;
        
// The reason why I think this works:
// 1. if sum of gas is more than sum of cost, then there must be a solution. And the question guaranteed that the solution is unique(The first one I found is the right one).
// 2. The tank should never be negative, so restart whenever there is a negative number.
        
        for(int i=0; i < gas.size(); i++){
            sumGas += gas[i];
            sumCost += cost[i];
            tank += gas[i] - cost[i];
            
            if(tank < 0){
                tank = 0;
                start = i + 1;
            }
            
        }
        
        if(sumGas < sumCost) return -1;
        
        return start;
        
    }
};
