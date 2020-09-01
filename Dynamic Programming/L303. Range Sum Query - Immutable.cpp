/*
 * Author : Shruti Katyal
 * Date   : 11 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class NumArray {
    vector<int> cumSum;
public:
    NumArray(vector<int>& nums) {
        cumSum.resize(nums.size() + 1);
        cumSum[0] = 0;
        
        for(int i=0; i<nums.size(); i++)
            cumSum[i+1] += cumSum[i] + nums[i];
        
    }
    
    int sumRange(int i, int j) {
        
        return cumSum[j+1] - cumSum[i];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
