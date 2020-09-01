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
    int countLargestGroup(int n) {
        
        //The sum can range between 1 and 36 because 9999 = 36
        int map[37] = {0}, maxSum = 0, groups = 0;
        
        for(int i=1; i<=n; i++){
            
            int sum = 0, num = i;
            
            while(num){
                sum += num % 10;
                num = num/10;
            }
            
            map[sum]++;
            
            if(map[sum] > maxSum){
                maxSum = map[sum];
                groups = 1;
            }
            else if(map[sum]==maxSum)
                groups++;
            
        }
        
        return groups;
    }
};
