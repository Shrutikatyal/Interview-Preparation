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
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> map; //value, count ,start, end
        
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) == map.end())
                map[nums[i]] = {1,i,i};
            else
            {
                map[nums[i]][0]++;
                map[nums[i]][2] = i;
            }
        }
        
        int len = INT_MAX;
        int maxCount = 0;
        
        for(auto value: map){
            if(value.second[0] > maxCount){
                maxCount = value.second[0];
                len = value.second[2]-value.second[1]+1;
            }
            else if(value.second[0] == maxCount)
                len = min(len, value.second[2]-value.second[1]+1);
                
        }
        
        return len;
    }
};
