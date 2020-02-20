/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreatest;
        stack<int> s;
        vector<int> res;
        int elt;
        
        if(!nums1.size() || !nums2.size())
            return res;
            
        s.push(nums2[0]);
        for(int i=1;i<nums2.size();i++) {
            if(!s.empty()){
                elt = s.top();
                
                while(elt < nums2[i]) {
                    s.pop();
                    nextGreatest[elt] = nums2[i];
                    if(s.empty())
                        break;
                    elt = s.top();
                }
            }
            s.push(nums2[i]); 
        }
        
        while(!s.empty()) {
            nextGreatest[s.top()] = -1;
            s.pop();
        }
        
        for(int n:nums1)
            res.push_back(nextGreatest[n]);
        
        return res;
    }
};
