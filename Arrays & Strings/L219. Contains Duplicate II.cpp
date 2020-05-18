/*
 * Author : Shruti Katyal
 * Date   : 14 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        
        for(int i=0; i < nums.size(); i++){
            
            if(map.find(nums[i]) == map.end())
                map[nums[i]] = i;
            
            else if(i - map[nums[i]] <= k)
                return true;
            else
                map[nums[i]] = i;
                
        }
        
        return false;
    }
};
