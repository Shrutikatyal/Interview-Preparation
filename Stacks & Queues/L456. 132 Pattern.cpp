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
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        //find s1s3s2
        int s2 = INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            
            //This means s1 found
            if(nums[i]<s2)
                return true;
            
            //This means s3 mil gya and we will maintain highest candidate for s2
            while(!st.empty() && nums[i] > st.top()){
                s2 = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};
