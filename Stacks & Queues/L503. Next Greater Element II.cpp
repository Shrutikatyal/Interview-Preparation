/*
 * Author : Shruti Katyal
 * Date   : 14 April, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int length = nums.size();
        vector<int> res(length);
        
        for(int i=2*length-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i%length])
                st.pop();
            res[i%length] = st.empty()? -1:nums[st.top()];
            st.push(i%length);
        }
        
        return res;
    }
};
