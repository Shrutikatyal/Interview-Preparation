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
    int dominantIndex(vector<int>& nums) {
        
        int firstMax = 0;
        int secMax = 0;
        int index = -1;
        
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > firstMax){
                secMax = firstMax;
                firstMax = nums[i]; 
                index = i;
            }
            else if(nums[i] > secMax){
                secMax = nums[i];
            }
                
        }
        
        return secMax*2 <= firstMax? index : -1;
    }
};


