/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        
        for(int num: nums2)
            if(set.count(num)){
                res.push_back(num);
                set.erase(num);
            }
        
        return res;
        
        
    }
};
