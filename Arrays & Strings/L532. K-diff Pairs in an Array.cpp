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
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> map;
        int count = 0;
        
        for(int num:nums) map[num]++;
        
        
        for(int i=0; i<nums.size(); i++)
            if((!k && map[nums[i]]>1 ) || (k && map[nums[i]+k])){
                count++;
                map[nums[i]+k] = 0;
            }
        return count;
    }
    
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> map;
        int count = 0;
        
        for(int num:nums) map[num]++;
        
        for(auto num:map){
            if( (!k && num.second > 1) || (k && map.count(num.first + k)))
                count++;
        }
        
        return count;
    }
    
};
