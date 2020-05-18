/*
 * Author : Shruti Katyal
 * Date   : 13 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

//Moore's Algorithm : Returns the most frequent element
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0];
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            //Count = 0 signifies switch in digit
            if(count==0)
                candidate = nums[i];
        
            count += (nums[i]==candidate)? 1: -1;
        }
        
        return candidate;
    }
};
