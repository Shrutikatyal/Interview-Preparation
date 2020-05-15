/*
 * Author : Shruti Katyal
 * Date   : 15 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    int minCostClimbingStairs2(vector<int>& cost) {
        int n = cost.size();
        
        //cost[i]: Denotes min cost for reaching level i
        //return cost[n]
        for(int i=2; i<n; i++)
            cost[i] += min(cost[i-1], cost[i-2]);

        return  min(cost[n-1], cost[n-2]);   
    
    }
    
     int minCostClimbingStairs(vector<int>& cost) {
         
         int firstStepCost = cost[0];
         int secStepCost = cost[1];
         
         for(int i=2; i <cost.size(); i++){
             int currCost = cost[i] + min(firstStepCost, secStepCost);
             firstStepCost = secStepCost;
             secStepCost = currCost; 
         }
         
         //We have to reach either last or secondLast step
         return min(firstStepCost, secStepCost);
     }

};
