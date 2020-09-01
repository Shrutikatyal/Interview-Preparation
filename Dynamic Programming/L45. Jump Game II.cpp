/*
 * Author : Shruti Katyal
 * Date   : 07 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, jumps = 0,end=0;
        for(int i=0; i<nums.size()-1; i++){       
            reach = max(reach, nums[i] + i);
            if(i==end){
                jumps++;
                end = reach;
            }
        }
        
        return jumps;
    }
};
