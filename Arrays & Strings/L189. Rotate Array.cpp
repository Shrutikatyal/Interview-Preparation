/*
 * Author : Shruti Katyal
 * Date   : 13 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k){
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k,nums.end());
        }
    }
};


