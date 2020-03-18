/*
 * Author : Shruti Katyal
 * Date   : 07 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size()+1);
        unordered_map<int,int> frequency;
        
        for(int num: nums){
            if(frequency.find(num)==frequency.end())
                frequency[num] = 1;
            else
                frequency[num]++;
        }
        
        for(auto pair: frequency){
            int freq = pair.second;
            buckets[freq].push_back(pair.first);
        }
        
        vector<int> res;
        for(int i=buckets.size()-1;i>=0 && res.size()<k;i--)
            res.insert(res.end(),buckets[i].begin(),buckets[i].end());
        
        return res;
    }
};
