/*
 * Author : Shruti Katyal
 * Date   : 01 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //Actually, we do not need to perfectly sort all cost differences, we just need the biggest savings (to fly to A) to be in the first half of the array. So, we can use the quick select algorithm (nth_element in C++) and use the middle of the array as a pivot.

        // sort(costs.begin(),costs.end(), [](vector<int> v1, vector<int> v2){
        //     return v1[0] - v1[1] < v2[0] - v2[1];
        // });
        
        nth_element(costs.begin(),begin(costs) + costs.size() / 2, costs.end(), [](vector<int> v1, vector<int> v2){
            return v1[0] - v1[1] < v2[0] - v2[1];
        });
        
        int cost=0;
        for(int i=0;i<costs.size()/2;i++)
            cost += costs[i][0] + costs[i+ costs.size()/2][1];
            
        return cost;
    }
};


