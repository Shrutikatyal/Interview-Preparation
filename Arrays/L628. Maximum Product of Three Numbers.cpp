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
    long maximumProduct(vector<int>& nums) {
      
        int firstMin = 1000;
        int secMin = 1000;
        int firstMax = -1000;
        int secMax = -1000;
        int thirdMax = -1000;
        
        for(int num : nums){
            
            if(num <= firstMin){
                secMin = firstMin;
                firstMin = num;
            }
            else if(num <= secMin){
                secMin = num;
            }
            
            if(num >= firstMax){
                thirdMax = secMax;
                secMax = firstMax;
                firstMax = num;
            }
            else if(num >= secMax){
                thirdMax = secMax;
                secMax = num;
            }
            else if(num >= thirdMax){
                thirdMax = num;
            }
        }
    
        
        return max(firstMin * secMin * firstMax, firstMax *secMax * thirdMax );
    }
};
