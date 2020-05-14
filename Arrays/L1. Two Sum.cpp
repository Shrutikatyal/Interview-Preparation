/*
 * Author : Shruti Katyal
 * Date   : 12 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include <map> 
#include <iterator> 
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> comp;
        vector<int> result(2);
    
        for(int i=0;i<nums.size();i++)
        {
            map<int, int>::iterator itr = comp.find(target-nums[i]); 
            if(itr!=comp.end())
            {
                result[0] = itr->second;
                result[1] = i;
                return result;   
            }
            else
                comp.insert(pair<int, int>(nums[i],i));
        }
        return result;
    }
};
