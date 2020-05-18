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
    bool isPerfectSquare(long num) {
        if(num <= 1) return true;
        
        long low = 1, high = num/2;
        
        while(low <= high){
            long mid = low + (high - low)/2;
            long sq = mid * mid;
            if(sq == num)
                return true;
            else if(sq < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
    
        return false;
    }
    
};
