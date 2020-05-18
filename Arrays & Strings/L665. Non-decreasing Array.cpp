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
    bool checkPossibility(vector<int>& nums) {
        int index = -1;
        for(int i=0; i < nums.size()-1; i++)
            if(nums[i] > nums[i+1]){
                
                if(index != -1)
                    return false;
                index = i;
            }
                
    	/*
    	If index = 0, then we could make the array good by setting A[index] = A[index+1].
    	Ex: 10 1 2 3 => 1 1 2 3
    	If index = len - 2 then we A[index + 1] = A[index]
    	Ex: 1 2 3 10 2 => 1 2 3 10 10    not A[index] = A[index+1] because that will make => 1 2 3 2 2 which is wrong
    	If index is in between A[index-1] <= A[index+1], A[index] = A[index+1] or anything between A[index-1] to A[index+1]
    	Ex: 1 2 3 6 4 5 => 1 2 3 4 4 5
		If index is in between A[index-1] > A[index+1] then check if A[index] <= A[index+2] if true then A[index+1] is the real culprit and
		A[index + 1] = anything between A[index]  and A[index+2].
		
		Ex: 1 2 3 6 2 7 => 1 2 3 6 6 7 
		*/
		
        return index == -1 || index == 0 || index == nums.size()-2  || nums[index-1] <= nums[index+1] || nums[index] <= nums[index+2];  
        
    }
};




