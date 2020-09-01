/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = 0, sum = 0;
        
        for(int i=0; i < nums.size(); i++){
            sum += nums[i];
            
            if(sum <= 0){
                min += abs(sum) + 1;
                sum = 1;
            }
                
        }
            
        if(min == 0)
            return 1;
        else
            return min;
    }
};
