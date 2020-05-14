/*
 * Author : Shruti Katyal
 * Date   : 14 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
	
	/*
		Other Solutions:
		1. Sorting
		2. Set
		3. Brute force
	*/
	
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]] > 1)
                return 1;
        }
            
        return 0;
    }
};
