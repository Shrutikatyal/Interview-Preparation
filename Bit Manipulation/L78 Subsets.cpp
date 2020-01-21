/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include<math.h>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> powerSet;
        
        int size=pow(2,nums.size());
        for(int i=0;i<size;i++)
        {
            vector<int> subset; 
            for(int j=0;j<nums.size();j++)
                if(i & 1<<j)
                   subset.push_back(nums[j]);
            
            powerSet.push_back(subset);
        }
        
        return powerSet;
    }
};




