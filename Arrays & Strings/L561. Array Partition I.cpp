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
    int arrayPairSum2(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i < nums.size()-1; i+=2)
            sum += min(nums[i],nums[i+1]);
        
        return sum;
    }
    
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        vector<int> map(20001);
        
        for(int num:nums) map[num+10000]++;
        
        int odd = true;
        for(int i=0;i<20001;i++){
            while (map[i] > 0) {
				if (odd) {
					sum += i - 10000;
				}
				odd = !odd;
				map[i]--;
			}
        }
        
        return sum;
    }
};




