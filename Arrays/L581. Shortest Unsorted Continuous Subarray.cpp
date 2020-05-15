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
    int findUnsortedSubarray2(vector<int>& nums) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        //FIND MIN WHICH IS MISPLACED
        for(int i=1; i < nums.size(); i++)
            if(nums[i] < nums[i-1])
                minimum = min(nums[i], minimum);
        
        //FIND MAX WHICH IS MISPLACED
        for(int i=nums.size()-2; i>=0; i--)
            if(nums[i] > nums[i+1])
                maximum = max(maximum, nums[i]);
        
        //FIND THE CORRECT POSITION FOR MIN
        int left;
        for(left = 0; left < nums.size(); left++)
            if(minimum < nums[left])
                break;
        
        //FIND THE CORRECT POSITION FOR MAX
        int right;
        for(right = nums.size() - 1; right >= 0; right--)
            if(maximum > nums[right])
                break;
        
        return right - left < 0? 0 : right - left + 1;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int beg = -1 , end = -2 , maximum = nums[0], minimum = nums[n-1];
        
        for(int i=1; i < n; i++){
            
            maximum = max(nums[i], maximum);
            minimum = min(nums[n-i-1], minimum);
            
            if(maximum > nums[i]) end = i;
            if(minimum < nums[n-i-1]) beg = n-i-1;
        }
        
        return end - beg + 1;
    }
};

